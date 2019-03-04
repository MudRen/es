#include "../../echobomber.h"

int pull_lever(object room,string str)
{
    int i,dir_num;
    string pre_direction,new_direction;
    mapping all_exits;
    
    if (!str||str!="lever") return 0;
    
    this_player()->set_explore("deathland#15");
    all_exits= room->query("exits") ;  
    switch( (pre_direction=room->query("direction")) ) {
      case "southeast": dir_num=1;break;
      case "south"    : dir_num=2;break;
      case "southwest": dir_num=3;break;
      }
    
    while(1) {
      dir_num=(dir_num==3) ? 1 : dir_num+1 ;
      switch (dir_num) {
        case 1: new_direction="southeast";break;
        case 2: new_direction="south";break;
        case 3: new_direction="southwest";break;
        }
      if ( ! undefinedp(all_exits[new_direction]) ) break;
      }
    room->set("direction",new_direction);
    write( "���������Ƹ˵�ʱ��,���ϵ����컺������"+ to_chinese(pre_direction)+
     "ת��"+to_chinese(new_direction)+"��\n"); 

    return 1;
}

