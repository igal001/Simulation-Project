//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package inet.networklayer.RPL;

import inet.networklayer.ipv6.RoutingTable6;
import inet.nodes.ipv6.NetworkLayer6;
import inet.networklayer.icmpv6.ICMPv6;
import inet.base.NotificationBoard;
import inet.linklayer.ieee80211.Ieee80211NicAdhoc;
import inet.mobility.BasicMobility;
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.RPL.RPLrouter;
//
// Models a mobile host with a wireless (802.11b) card in ad-hoc mode.
// This model contains the new IEEE 802.11 implementation, Ieee80211Nic,
// and IP, TCP and UDP protocols. The mobility model can be
// dynamically specified with the mobilityType parameter.
//
// @see MFMobileHost, WirelessHost
//
module MobileHostRPL
{
    parameters:
        @node();
        @labels(node,wireless-node);
        bool IPForward = default(false);
        string routingFile = default("");
        string mobilityType = default("NullMobility");
        @display("i=device/pocketpc_s");
        int DODAGsize = default(1);
        int numHosts;
    gates:
        input radioIn @directIn;
        inout io[numHosts] @loose;
    submodules:
        notificationBoard: NotificationBoard {
            parameters:
                @display("p=225,49");
        }
        interfaceTable: InterfaceTable {
            parameters:
                @display("p=138,49");
        }
        wlan: Ieee80211NicAdhoc {
            parameters:
                @display("p=138,226;q=queue");
        }
        mobility: <mobilityType> like BasicMobility {
            parameters:
                @display("p=48,235");
        }
        networkLayer6: NetworkLayer6 {
            @display("p=138,137");
        }
        routingTable6: RoutingTable6 {
            isRouter = true;
            @display("p=48,49");
        }
        RPLrouter: RPLrouter {
            @display("p=225,137");
        }
    connections allowunconnected:
        // connections to network outside
        radioIn --> wlan.radioIn;
        wlan.uppergateOut --> networkLayer6.ifIn[0];//////////////out ipv6
        wlan.uppergateIn <-- networkLayer6.ifOut[0];

        networkLayer6.t_RPL --> RPLrouter.t_RPL;
        networkLayer6.f_RPL <-- RPLrouter.f_RPL;
}

