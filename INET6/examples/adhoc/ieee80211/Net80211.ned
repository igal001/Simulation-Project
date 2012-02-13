//
// Copyright (C) 2006 Andras Varga
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//

package inet.examples.adhoc.ieee80211;

import inet.networklayer.autorouting.FlatNetworkConfigurator6;
import inet.nodes.ipv6.StandardHost6;
import inet.networklayer.autorouting.FlatNetworkConfigurator;
import inet.world.ChannelControl;
import inet.networklayer.RPL.MobileHostRPL;

network Net80211
{
    parameters:
        int numHosts;
        double playgroundSizeX;
        double playgroundSizeY;
        int radius;
    submodules:
        host[numHosts]: MobileHostRPL {
            parameters:
                numHosts = numHosts;
                @display("p=188,98");
        }
        channelcontrol: ChannelControl {
            parameters:
                playgroundSizeX = playgroundSizeX;
                playgroundSizeY = playgroundSizeY;
                radius = radius;
                @display("p=15,16");
        }
        flatNetworkConfigurator6: FlatNetworkConfigurator6 {
            @display("p=379,17");
        }
}

