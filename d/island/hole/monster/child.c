#include <../hole.h>

inherit MONSTER;
void create()
{
        ::create();
        set_level(5);
        set_name( "Lizardman child", "������С��" );
        add("id",({"lizardman","child" }) );
        set_short( "������С��" );
        set_long(@LONG
�㿴��һλ������õ�С���������ڹ㳡�Ϻ�
ⷰ�������Ϸ
LONG
        );
        set( "gender","male" );
        set( "race","lizardman" );
        set( "alignment",600 );
        set( "wealth/silver",10 );
        set_perm_stat( "str",10 );
        set_perm_stat( "dex",13 );
        set_natural_armor( 20,5 );
        set_natural_weapon( 2,0,2 );
        set_skill( "parry",40 );
        wield_weapon( HWEAPON"bat" );
}

