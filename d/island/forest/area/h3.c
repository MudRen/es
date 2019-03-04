#include "../tsunami.h"
#include <daemons.h>

inherit HOME+"magic";
inherit ROOM;

void create()
{
    ::create();
    set_short("��������");
    set_long(@LONG
�����ǿ��ӭ�����±����������Ϯ�˹������ݷ�������ı޴�������
�ģ�û�����������ħ���������ߴ������ۿ�ȥ�������������У�ǰ����
������һƬ����£�û���˸����׿��������±�ǿ����䣻Ҳ����Ϊ֤����
�������߶�������ȥ(jump)������û�������м�ʯͷ���м�����(words)��
LONG
            );
     set("light",1);
     set_outside("island");
     set("item_desc",(["words":@WORDS

������Ψ��������Ĵ��ڣ�����֤�����ҵļ�ֵ�����ܳ�Ϊ�������¼汸�����ߣ���
         
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
    ��Ҫ���Ķ���ѽ�����ֻ��������Ү����
ALONG
          );
     return 1;
     }      

     if( !this_player()->query_explore("island#1") ) {
     write("\n��ͻȻһ��ʧ�� ..... \n");
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
               ������ģ�Ŭ������ǰһԾ........
BLONG
          );                                                             
     
     sscanf(WEATHER_D->query_game_time(),"%d",hour);
     if( hour >= 16 && hour <= 23){
       tell_room(environment(this_player()),
         this_player()->query("c_name")+"�ܳ嶯��������Ծ����ȥ........\n"
         ,this_player() );
       this_player()->move_player(AREA"upriver2","SNEAK");
       write("��մ���һ��������������ú��ӣ������ľ���\n");
       tell_room(environment(this_player()),
         this_player()->query("c_name")+"�����������������Ʈ��.......\n"
         ,this_player() );
       return 1;
     }
     else{
       tell_room(environment(this_player()),
         "ͻȻ���һ����"+this_player()->query("c_name")+"һ��С�ĵ��������ˣ�\n"
         ,this_player() );
       this_player()->move_player(AREA"river2","SNEAK");
       tell_room(environment(this_player()),
         this_player()->query("c_name")+"�Լ��ѿ�����������ˮ�У������룺��������..\n"
         ,this_player() );
     this_player()->set("hit_points",(int)this_player()->query("hit_points") / 10);
     report(this_object(),this_player());
     return 1; 
         } 
    }
}