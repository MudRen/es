#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(9);
	set_name( "female servant", "��Ů" );
	add("id",({"servant"}));
	set_short( "��Ů");
	set_long(@C_LONG
һɫǳ�ƹ�װ��Ů�ڡ������ڷ�����������
C_LONG
        );
        set( "wealth/silver",80);
        set( "gender","female");
        set_natural_armor(45,0); 
        set_natural_weapon( 15,7,15 );
}
