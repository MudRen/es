#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("�����Ǳ���");
    set_long(@LONG
������ħ��Ļʳǣ������ǵı��ţ�������������ǵĲ��ݣ����в���
��Ϊħ����Ƚ������е�������ѡ������������������������ܹ����ɣ���
б�壬����죬���ֱͦ����Ȼ�����޷���⣬ȴ����е���Э�����෴��
���������̲�ס���뿪�������أ�
LONG
            );
    set("light",1);
    set("exits",([
        "south":CITY"r2",
        "north":AREA"way2"]) );
    
    set("objects",([
        "soldier#2":TMOB"soldier",
        "soldier#1":TMOB"soldier"]) );
  
    set("pre_exit_func",([
            "south":"do_say"]));
    set_outside("island");
    reset();
}

void init()
{ add_action("do_say","say"); }

int do_say(string arg)
{
   if( !present("soldier"))
   return 0; 
   
   if( !arg ){
   write("\nħ��ʿ�����������㣺ι����һ�£�����ͨ�����룬��Ȼ��׼��ȥ��\n\n");
   return 1;}
   
   if( arg != "��ͷެ��") {
   write("\nʿ�������Ĵ�������ι������֨֨����ʲ�᣿����ֻ׼˵���룡\n\n");
   return 1; }
  
   if( !this_player()->query_explore("island#2") ) {
   write("\nʿ����ݺݵص���һ�ۣ�˵������Ҫ��Ϊ�Ҳ�֪����������ƭ���� !\n");
   write("ʿ���󺰵����ٲ��ߵĻ���Ҫ����� !!\n");
   return 1;}
               
   write("\nʿ���ͻ���˵���ţ�������ȷ���㲻����ʿ���������ѵļ�ϸ���ã���ȥ�ɣ�\n\n");
   tell_room( environment(this_player()),
     "ʿ���ߴ���"+this_player()->query("c_name")+"�Ͽ�ͨ����\n",
     this_player() );
   this_player()->move_player(CITY"r2","SNEAK");
   tell_room( environment(this_player()),
     this_player()->query("c_name")+"�첽�����˹�����\n",
     this_player() );
   return 1;
}   
   
    
