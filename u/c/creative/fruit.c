#include <mudlib.h>

inherit OBJECT;

void init()
{
        add_action( "eat_food", "eat" );
}

void create()
{
        
        set_name("red fruit","���");
        add( "id" , ({ "fruit" }) );
   set_short("���");
   set_long(@C_LONG
һ�ų��ɫ�Ĺ�ʵ��ɢ����Ũ���ķ��㣬�������ܺóԵ����ӡ�
C_LONG
        );
        set("unit","��");
        set("weight", 30);
        set("no_sale",1);
        set("value",({ 500, "silver" }) );
}

int eat_food(string arg)
{
    if( !arg ||( arg != "fruit") ) 
        return notify_fail("��Ҫ��ɶ������?\n");
    tell_object( this_player(),
        "�������һ��������������Ƿ��㡣\n");
this_player()->set("max_hp",5000);
this_player()->set("max_sp",5000);
    this_player()->receive_healing( 5000 );
    this_player()->add("force_points",5000);
      this_player()->add("spell_points",5000);
       remove();
    return 1;
}
