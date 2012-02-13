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

import inet.networklayer.RPL.RPLapp;
import inet.networklayer.RPL.Trickle;
import inet.networklayer.RPL.DODAGtable;
//
// TODO auto-generated type
//
module RPLrouter
{
    parameters:
    	@display("i=block/network2");
    	int DODAGsize = default(1);
    gates:
        input t_RPL;
        output f_RPL;
    submodules:
        DODAGtable: DODAGtable {
            @display("p=49,59");
        }
        RPLapp: RPLapp {
            @display("p=129,71");
        }
        trickle[DODAGsize]: Trickle {
        }

    connections allowunconnected:
        for i=0..DODAGsize-1 {
       		RPLapp.t_Trickle++ --> trickle[i].f_RPL;
        	RPLapp.f_Trickle++ <-- trickle[i].t_RPL;
        }
        RPLapp.t_ICMP --> f_RPL;
        RPLapp.f_ICMP <-- t_RPL;
}
