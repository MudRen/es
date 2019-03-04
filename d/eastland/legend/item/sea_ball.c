#include "../legend.h"
#include <mudlib.h>

inherit OBJECT;

void create()
{
     seteuid(getuid());
     set_name("Sea Ball", "������");
     add("id", ({ "sea ball","ball" }) );
     set_short("������");
     set_long(@C_LONG
һ�ŵ���ɫ������,����ԼԼ��������ѶϢ��
C_LONG
     );                             
     set( "unit", "��" );
     set( "no_sale",1);
}
void init()
{
   add_action("do_roll","roll");
}
int do_roll(string arg)
{
    object holder,env;
    if ( !arg || arg!="sea-ball" ) 
       return 0;
    holder=environment(this_object());
    if ( !living(holder) ) 
       return 0;    
    env=environment(holder);
    if ( !env->query("can_use_sea_ball") )
       return 0;
    if ( env->query("exits/tunnel") ) {
       tell_object(holder,"���Ｚ����һ��ͨ�� ( tunnel ) ��!\n");       
       return 1;
    }
    if ( present("water beast",env) ) 
      return 0;
    holder->set_temp("block_command",1);
    tell_object(holder,set_color(
        "\n\n       ����������������Ħ����������..\n\n\n",
        "HIC"));
    tell_room(env,set_color(sprintf(
        "\n\n       %s���������������Ħ����������..\n\n\n",holder->query("c_name")),
        "HIC"),holder);   
    call_out("recover1",2,holder,env);       
    return 1;
}
void recover1(object holder,object env)
{
    tell_room(env,set_color(
       "\n\n       ��Ȼ�䣡�����沨�ˡ��졢�׵罻�ӣ������ն�....\n\n"
       "       �������������õ�Ԥ�У���\n\n"
       ,"HIC"));
    call_out("recover2",6,holder,env);
}    
void recover2(object holder,object env)
{
    object beast; 
    holder->delete_temp("block_command");
    tell_room(env,set_color( 
       "\n\n       �䣡һ�����紹ֱ������棡��\n\n" 
       "       ��������ᣬ��������ԼԼ�س���һ���� ( water-tunnel ) ����\n\n\n"
       ,"HIC"));
    if ( !beast=present("water beast",env) ) {
       beast=new(LMONSTER"water_mob");
       beast->move(env);  
    }
    env->add("exits/tunnel",LAKE"lake1");
    env->add("c_item_desc/water-tunnel","һ��ˮ�� ( tunnel ),���Զ����ɸߵ�ˮǽ��\n");
    env->set( "exit_suppress", ({
                   "tunnel"}) );
    this_object()->remove();
}
