#include "../tsunami.h"
#include "/include/move.h"
inherit ROOM;

int left_hole,mid_hole,right_hole;
void create()
{
    ::create();
    set_short("��а��");
    set_long(@LONG
����а�������ڽ���֮ǰ���Ѿ�����춴˵���Ȼ��ʯ���ഫ����ħ��
����Ǩ�����˵�ʱ��������һֻ�ǳ����µĴ��ħϮ������ʱ��λ�ػ�����
�飬����������Կ����������һ���භ�ᣬ�Ѷ�ħ��ӡ��˾�ʯ֮���С�Ŀ
ǰ������������������������Ϊ��������������Ŭ����
LONG
             );
    set_outside("island");
    set("objects",([
         "stone":TOBJ"stone"]) );
    set("exits",([
        "south":CITY"inway3"]) );
    set("light",1);
    left_hole=0;
    mid_hole=0;
    right_hole=0;
    reset();
}

void init()
{
    add_action("do_insert","insert");
}

int do_insert(string arg)
{
  string name,dir;
  object obj,ob;
  
  ob=new(TOBJ"ball");
  
  if ( !arg || (sscanf(arg,"%s into %s hole",name,dir)!=2 ) )
    return notify_fail( "��ʽ:insert <key name> into <dir> hole\n" );
  
  if( dir!="right" && dir!="middle" && dir!="left" )
    return notify_fail("��left��middle��right�����������Ǹ����˨ߣ�\n");
  
  if ( !( obj=present( name,this_player() ) ) )
    return notify_fail("��û����������\n");
    
  if( name!="luoko" && name!="janser" && name!="tsunami" )
  {
    obj->remove();
    return notify_fail( 
    "ʯͷ��ð��һ��������Ц����лл�㣡�ⶫ��ζ������ร�\n" );
   } 
    
    switch(name) {
    case "luoko" : switch(dir) {
                  case "left" :
                        if( left_hole == 1){
                        write("������Ѿ����Կ������...���ǵģ�\n");
                        return 1;
                        }                 
                        write("�㽫���е���Կ������ߵĶ��У��ۡ���!�ɹ��ˡ�\n");
                        left_hole=1;
                        obj->remove();
                        break;
                  case "middle" :
                        write("�㽫���е���Կ�����м�Ķ��У����Ǻ����С����Ү��\n");
                        return 1;
                  case "right" :
                        write("�㽫���е���Կ�����ұߵĶ��У����Ǻ����С����Ү��\n");
                        return 1;
                  default:
                    return 0;
                  };
         break;
         
    case "janser" : switch(dir) {
                  case "left" :
                        write("�㽫���е���Կ������ߵĶ��У����Ǵ�С���񲻺�Ү��\n");
                        return 1;
                  case "middle" :
                        write("�㽫���е���Կ�����м�Ķ��У����Ǵ�С���񲻺�Ү��\n");
                        return 1;
                  case "right" :
                        if( right_hole == 1){
                        write("������Ѿ����Կ������...���ǵģ�\n");
                        return 1;
                        }
                        write("�㽫���е���Կ�����ұߵĶ��У��ۡ������ɹ��ˡ�\n");
                        right_hole=1;
                        obj->remove();
                        break;
                  default:
                    return 0;
                  };
         break;
         
    case "tsunami" : switch(dir) {
                  case "left" :
                        write("�㽫���е���Կ������ߵĶ��У����Ǵ�С���񲻺�Ү��\n");
                        return 1;
                  case "middle" :
                        if( mid_hole == 1){
                        write("������Ѿ����Կ������...���ǵģ�\n");
                        return 1;
                        }
                        write("�㽫���е���Կ�����м�Ķ��У��ۡ������ɹ��ˡ�\n");
                        mid_hole=1;
                        obj->remove();
                        break;
                  case "right" :
                        write("�㽫���е���Կ�����ұߵĶ��У����Ǵ�С���񲻺�Ү��\n");
                        return 1;
      		  default:
      		    return 0;
                  };
         break;
         
    default :
          return notify_fail("The syntax: insert <key name> into <position> hole\n");
    }
    
    if ( left_hole==1 && mid_hole==1 && right_hole==1 )
    {
       if( (int)this_player()->query_temp("get_key") == 1 ) {
              tell_room( environment(this_player()),@ALONG

ͻȻ��а�����Χ�������ҵ��𶯣�һ������֮�ᣬһ�ù���������ʯ�Ϸ�.......

ALONG
                );    
              ob->move(environment(this_player())); 
              this_player()->set_temp("holy_knight",1);
//              if( (int)this_player()->query_quest_level("get_ball") < 1) {
//              write("��ϲ������ʹ�������Ԫ��������õ�15000�㾭���\n");
//              this_player()->finish_quest("get_ball",1);
//              this_player()->gain_experience(15000);
//              }
              left_hole=0;
              mid_hole=0;
              right_hole=0;
              this_player()->set_explore("island#5");
              return 1;
          }
          else{
    write(@LONG
      ��˳���Ĳ���Կ�ף��������û��һ��Կ�����������õ��ֵģ�
      ������������һƬ�ž�����������������һֻ���ѻ����ɹ�......-|:
LONG
         ); 
          left_hole=0;
          mid_hole=0;
          right_hole=0; 
              }        
        return 1;
    } 
    return 1;
}
