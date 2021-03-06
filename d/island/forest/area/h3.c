#include "../tsunami.h"
#include <daemons.h>

inherit HOME+"magic";
inherit ROOM;

void create()
{
    ::create();
    set_short("神武悬崖");
    set_long(@LONG
阵阵的强风迎著悬崖壁向你的身躯袭了过来，彷佛正无情的鞭打著你似
的；没错，这儿正是魔族国境的最高处，放眼看去，国境尽入眼中；前方几
步处是一片大断崖，没有人敢轻易靠近，深怕被强风卷落；也有人为证明自
己是勇者而跳了下去(jump)，但都没回音；中间石头上有几个字(words)！
LONG
            );
     set("light",1);
     set_outside("island");
     set("item_desc",(["words":@WORDS

　　『唯有相信神的存在，方能证明自我的价值，才能成为真正智勇兼备的勇者！』
         
WORDS
                     ]) );
     set("exits",(["north":AREA"h2"]) );
}

void init()
{
     add_action("do_jump","jump");
}

int do_jump(string str)
{
     int hour;
     
     if( !(this_player()) ) return 0;
     if( !str || str!="down" )
     {
     write(@ALONG
    你要往哪儿跳呀？这儿只能往下跳耶！！
ALONG
          );
     return 1;
     }      

     if( !this_player()->query_explore("island#1") ) {
     write("\n你突然一个失足 ..... \n");
     this_player()->move_player(AREA"upriver2","SNEAK");
     this_player()->set("hit_points",1);
     this_player()->set("spell_points",1);
     this_player()->set("talk_points",1);
     this_player()->set("force_points",1);
     this_player()->set("block_command",1);
     call_out("remove_block",10,this_player() );
     return 1;
     }
     else {
         write(@BLONG
               你奋力的，努力的向前一跃........
BLONG
          );                                                             
     
     sscanf(WEATHER_D->query_game_time(),"%d",hour);
     if( hour >= 16 && hour <= 23){
       tell_room(environment(this_player()),
         this_player()->query("c_name")+"很冲动地向悬崖跃了下去........\n"
         ,this_player() );
       this_player()->move_player(AREA"upriver2","SNEAK");
       write("天空传来一阵轻柔的声音：好孩子，聪明的抉择！\n");
       tell_room(environment(this_player()),
         this_player()->query("c_name")+"以完美的姿势自天空飘下.......\n"
         ,this_player() );
       return 1;
     }
     else{
       tell_room(environment(this_player()),
         "突然大风一吹，"+this_player()->query("c_name")+"一不小心掉下悬崖了！\n"
         ,this_player() );
       this_player()->move_player(AREA"river2","SNEAK");
       tell_room(environment(this_player()),
         this_player()->query("c_name")+"以极难看的姿势跳入水中，你心想：唉，两分..\n"
         ,this_player() );
     this_player()->set("hit_points",(int)this_player()->query("hit_points") / 10);
     report(this_object(),this_player());
     return 1; 
         } 
    }
}