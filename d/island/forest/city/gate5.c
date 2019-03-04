#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("�ڳ�����");
    set_long(@LONG
�������������Ҿ�ס�����ڳǵ����ţ�������������ǵĲ��ݣ����в�
�ɵ�Ϊħ����Ƚ������е�������ѡ������������������������ܹ����ɣ�
��б�壬����죬���ֱͦ����Ȼ�����޷���⣬ȴ����е���Э�����෴
�ģ��������̲�ס���뿪�������أ�
LONG
            );
    set("light",1);
    set("exits",([
        "south":CITY"r6",
        "north":CITY"inway4"]) );
    
    set("objects",([
        "soldier#2":TMOB"warrior",
        "soldier#1":TMOB"warrior"]) );
  
    set("pre_exit_func",([
            "north":"do_say"]));
    set_outside("island");
    reset();
}

void init()
{ add_action("do_say","say"); }

int do_say(string arg)
{
   if( !present("warrior"))
   return 0; 
   
   if( !arg ){
   write("\nħ��սʿ���������㣺ι����һ�£�����ͨ�����룬��Ȼ��׼��ȥ��\n\n");
   return 1;}
   
   if( arg != "�ܾúܾ���ǰ��һ���Ϲ�����һ��������") {
   write(@ALONG
    սʿ�����Ĵ���������֪������ȥ�ʽ�������Ҫ����������˽��
��С���Һ�����һ��Ŷ��
ALONG
         );
   return 1; }
   
   if( !this_player()->query_explore("island#3") ) {
   write("\nսʿ����������۾�������һ�����˵����\n");
   write("\n��Ҫ��Ϊ�������������������ܻ��ȥ��������� !!\n");
   return 1;}
   
   write("\nսʿ�ͻ���˵���ţ�������ȷ���㲻����ʿ���������ѵļ�ϸ���ã���ȥ�ɣ�\n\n");
   tell_room( environment(this_player()),
     "սʿ����ʾ��"+this_player()->query("c_name")+"�Ͽ�ͨ����\n",
     this_player() );
   this_player()->move_player(CITY"inway4","SNEAK");
   tell_room( environment(this_player()),
     this_player()->query("c_name")+"ηη���������˹���!\n",
     this_player() );
   return 1;
}   
   
    
