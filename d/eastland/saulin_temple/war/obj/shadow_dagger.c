
#include "mudlib.h"

inherit WEAPON;

void create()
{
       set_name("shadow dagger","��Ӱذ��");
       add("id",({"dagger",}) );
       set_short("��Ӱذ��");
       set_long(@C_LONG
����һ�Ѵӵ��е�����ͨ���ںڵ�ذ�ף�ͨ����ɱ��������������
�İ�ɱ�ж���
C_LONG
        );

        set( "unit", "��" );
        set( "weapon_class", 19 );
	set("type","dagger");
        set( "min_damage", 12 );
	set( "max_damage", 20 );
        set( "weight", 34 );
        set( "value", ({ 450 , "silver" }) );
}