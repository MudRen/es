#include "../tsunami.h"
#include "/include/move.h"
inherit ROOM;

int left_hole,mid_hole,right_hole;
void create()
{
    ::create();
    set_short("破邪镇");
    set_long(@LONG
『破邪镇』是早在建都之前就已经存在於此的天然巨石，相传当年魔族
祖先迁徙至此地时，遭遇到一只非常可怕的大恶魔袭击，当时三位守护灵显
灵，集合三把主钥的力量，在一番苦斗後，把恶魔封印予此巨石之下中。目
前是用来告诫後世子孙，勿忘祖先为守卫疆土所作的努力。
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
    return notify_fail( "格式:insert <key name> into <dir> hole\n" );
  
  if( dir!="right" && dir!="middle" && dir!="left" )
    return notify_fail("有left，middle，right三个洞，插那个洞ㄋㄟ？\n");
  
  if ( !( obj=present( name,this_player() ) ) )
    return notify_fail("你没有这样东西\n");
    
  if( name!="luoko" && name!="janser" && name!="tsunami" )
  {
    obj->remove();
    return notify_fail( 
    "石头中冒出一阵狰狞的笑声：谢谢你！这东西味道不错喔！\n" );
   } 
    
    switch(name) {
    case "luoko" : switch(dir) {
                  case "left" :
                        if( left_hole == 1){
                        write("这个洞已经插过钥匙了啦...真是的！\n");
                        return 1;
                        }                 
                        write("你将手中的主钥插入左边的洞中，哇～～!成功了。\n");
                        left_hole=1;
                        obj->remove();
                        break;
                  case "middle" :
                        write("你将手中的主钥插入中间的洞中，可是好像大小不合耶。\n");
                        return 1;
                  case "right" :
                        write("你将手中的主钥插入右边的洞中，可是好像大小不合耶。\n");
                        return 1;
                  default:
                    return 0;
                  };
         break;
         
    case "janser" : switch(dir) {
                  case "left" :
                        write("你将手中的主钥插入左边的洞中，可是大小好像不合耶。\n");
                        return 1;
                  case "middle" :
                        write("你将手中的主钥插入中间的洞中，可是大小好像不合耶。\n");
                        return 1;
                  case "right" :
                        if( right_hole == 1){
                        write("这个洞已经插过钥匙了啦...真是的！\n");
                        return 1;
                        }
                        write("你将手中的主钥插入右边的洞中，哇～～！成功了。\n");
                        right_hole=1;
                        obj->remove();
                        break;
                  default:
                    return 0;
                  };
         break;
         
    case "tsunami" : switch(dir) {
                  case "left" :
                        write("你将手中的主钥插入左边的洞中，可是大小好像不合耶。\n");
                        return 1;
                  case "middle" :
                        if( mid_hole == 1){
                        write("这个洞已经插过钥匙了啦...真是的！\n");
                        return 1;
                        }
                        write("你将手中的主钥插入中间的洞中，哇～～！成功了。\n");
                        mid_hole=1;
                        obj->remove();
                        break;
                  case "right" :
                        write("你将手中的主钥插入右边的洞中，可是大小好像不合耶。\n");
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

突然破邪镇的周围产生剧烈的震动，一声巨响之後，一棵光球浮现在岩石上方.......

ALONG
                );    
              ob->move(environment(this_player())); 
              this_player()->set_temp("holy_knight",1);
//              if( (int)this_player()->query_quest_level("get_ball") < 1) {
//              write("恭喜你能忍痛完成拯救元神任务，你得到15000点经验点\n");
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
      你顺利的插完钥匙，但是由於没有一把钥匙是你亲自拿到手的，
      所以四周仍是一片寂静，啊～～有啦，有一只蜻蜓缓缓飞过......-|:
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
