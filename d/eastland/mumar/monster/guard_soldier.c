#include <../mumar.h>
inherit MONSTER;
 
void create()
{
        object ob1;
 
        ::create();
        set_level(4);
        set_name( "guard soldier", "�����" );
        set_short( "�����" );
        add( "id", ({ "guard","soldier" }) );
        set_long(
                "����һ�����������������صľ��䰲ȫ��\n"
        );
        set( "gender", "male" );
        set( "alignment", 100 );
        set( "killer", 1 );
        set( "wealth/silver", 40 );
        set( "natural_armor_class", 20 );
        set( "natural_defense_bonus", 6 );
        set_natural_weapon( 4,1,3 );
        set_perm_stat( "str", 3 );
        set_perm_stat( "dex", 7 );
        set_skill( "parry", 30 );
 
        set( "moving",1 );
        set( "pursuing",1 );
        set( "speed",50 );
 
        set( "chat_chance", 15 );
        set( "att_chat_output", ({
  "���������˵���������֣�����Ȩ���ּ�Ĭ��������������ص�Ϊ�ɴ�����!!����\n",
        }) );
 
        ob1 = new( OBJS"club" );
        ob1->move(this_object());
        wield_weapon(ob1);
}
