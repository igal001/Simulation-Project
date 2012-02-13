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


simple RPLapp 
{
    parameters:
        bool isRoot = default(false);
        @display("i=block/network2");
        int Sp = default(1);							//step_of_rank
//        int rank_inc = default(256);					//rank_increase
        int Sr = default(0);							//stretch_of_rank
        int Rf = default(1);							//rank_factor
        int MOP = default(1);							//mode of operation - non storing mode
        int PCS = default(0);
        int Imax = default(20);
		int Imin = default(3);
		int K = default(10);
		int MaxRankIncrease = default(0);
		int MinHopRankInc = default(256);
		int OCP = default(0);
		int DefaultLifetime = default(5);
		int LifetimeUnit = default(5);
		double startTime @unit("s") = default(uniform(0s,this.interval));
		string srcAddr = default(""); 	// source IP or IPv6 address (useful with multi-homing)
		int Grounded = default(1);
		int Prf = default(0);
		int VersionNumber = default(0);
		int RPLInstanceID = default(0);
		string RPLinstList = default("0");
		int DTSN = default(0);
		double A = default(0.05);
		int Metric = default(7);		//ETX default
		string const_ETX_values;
		string changed_ETX_values;
	gates:
		input f_ICMP;//to ICMP
		output t_ICMP;
		input RPLIn;//to network
		output RPLOut;
		input f_Trickle[];//to trickle
		output t_Trickle[];
}
