
#include "mudlib.h"

inherit WEAPON;

void create()
{
        set_name("staff of snake","����");
        add("id",({"staff",}) );
	set_short("����");
	set_long(@C_LONG
����һ����ڵĸ��ȣ����ɶ�ħ��׵���ͷ��������ֻ��ʰ�쵵�
�������µ�����������ʱ�������ţ��Եù���Ƿ���
C_LONG
               );

        set( "unit", "��" );
        set( "weapon_class", 24 );
	set("type","blunt");
        set( "min_damage", 15 );
        set( "max_damage", 30 );
	set( "weight", 180 );
        set( "value", ({ 170, "gold" }) );
}
