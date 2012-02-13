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

//
// TODO generated message class
//

cplusplus {{
    #include "IPv6Address.h"
}};

enum DIO_TYPE{
	Pad1 = 0;
	PadN = 1;
	Metric_Container = 2;
	Routing_Information = 3;
	DODAG_CONFIGURATION = 4;
	Prefix_Information = 8;
}

enum DIO_LENGTH{
    DIO_HEADER = 24;
    PAD1_LENGTH = 1;
	DODAG_CONFIGURATION_LENGTH = 14;
	Prefix_Information_LENGTH = 30;
	ETX_LENGTH = 6;
}


enum METRIC_TYPE{
    ETX_TYPE = 7;
}


class noncobject IPv6Address;


packet DIOheader{
   	uint8_t RPLInstance;		
    uint8_t VersionNumber;		
    uint16_t Rank;
    uint8_t GMP;						// grounded, '0' , MOP
    uint8_t DTSN;
    uint8_t Flags;
    uint8_t Reserved;
    IPv6Address DODAGID;				// root's IPv6 address 
}

packet DIOop{
    uint8_t Type enum(DIO_TYPE);
}

packet PAD1op extends DIOop{
}

packet PADNop extends DIOop{
    uint8_t Option_Length;
}

packet METRIC_CONTop extends DIOop{
    uint8_t Option_Length;
    //update metric container
    uint8_t RMCT enum(METRIC_TYPE);		// Routing Metric/Constraint Type 
    uint8_t FPC0;						// Res Flags, P, C, 0
    uint8_t RAP;						// R, A, Prec
    uint8_t Length;
}

packet ETX extends METRIC_CONTop{
    uint16_t ETX_VALUE;
}


packet ROUTING_INFOop extends DIOop{
    uint8_t Option_Length;
    uint8_t Prefix_Length;
    uint8_t RPR;						// Reserved, Prf, Reserved
    uint32_t Rout_Lifrtime;
    IPv6Address Prefix;
}

packet DODAG_CONFop extends DIOop{
    uint8_t Option_Length enum(DIO_LENGTH);
    uint8_t FAP;						// Flags, A, PCS
    uint8_t DIOIntDoubl;
    uint8_t DIOIntMin;
    uint8_t DIORedun;
    uint16_t MaxRankIncrease;
    uint16_t MinHopRankIncrease;
    uint16_t OCP;
    uint8_t Reserved;
    uint8_t Def_Lifetime;
    uint16_t Lifetime_Unit;
}

packet PREFIX_INFOop extends DIOop{
    uint8_t Option_Length enum(DIO_LENGTH);
    uint8_t Prefix_Length;
    uint8_t LARR;						// L, A ,R, Reserved1
    uint32_t Valid_Lifetime;
    uint32_t Prf_Lifetime;
    uint32_t Reserved2;
    IPv6Address Prefix;
}

packet DIOMessage extends DIOheader {
//    DIOdata data;   
}
