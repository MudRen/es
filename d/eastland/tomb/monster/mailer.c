#include <../almuhara.h>
inherit MONSTER;
 
void create()
{
        ::create();
        seteuid( getuid() );
        set_level(5);
        set_name( "mail man", "�Ų�" );
        set_short( "�Ų�" );
        add( "id", ({ "man" }) );
        set_long(
@C_LONG_DESCRIPTION
�㿴��һ���ٲ�����ˣ�������ǰ��һ������ĵ��ˣ�������һϢ������Ѱ��
��·�����������������ƺ��൱���ˣ������������Ѿ�û���������������ˡ�
C_LONG_DESCRIPTION);
        set( "gender", "male" );
        set( "max_hp",120);
        set( "hit_points",1);
        set( "natural_armor_class", 20 );
        set( "natural_defense_bonus", 10 );
        set( "no_attack",1 );
        set_natural_weapon(12,5,15);
        set( "inquiry", ([
        "help" : "@@ask_help" ]) );
}
 
int ask_help()
{
object obj;
tell_object(this_player(),
@ASK
 
�Ų���΢��������˵����..��......��........��.��....ʦ.......
�������ʸ����ʱ.....ȴ�������Ѿ�������.......
 
һ��������Ų�µ����е��䡣
 
Ҳ�������о綾���Ų�ġ���Ѹ�ٵػ���Ѫˮ......�������......
ASK);
obj=new("/d/eastland/tomb/item/break_jade1");
obj->move(environment(this_object()));
this_object()->remove();
}
