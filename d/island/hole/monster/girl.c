#include <../hole.h>

inherit MONSTER;
void create()
{
        ::create();
        set_level(7);
        set_name( "Lizardman Girl", "������СŮ��" );
        add("id",({"lizardman","girl" }) );
        set_short( "������СŮ��" );
        set_long(@LONG
�㿴��һλ���������СŮ���������ڹ㳡��
��ⷰ�������Ҽҡ�
LONG
        );
        set( "gender","female" );
        set( "race","lizardman" );
        set( "alignment",600 );
        set( "wealth/silver",10 );
        set_perm_stat( "str",12 );
        set_perm_stat( "dex",15 );
        set_natural_armor( 20,5 );
        set_natural_weapon( 2,3,8 );
        set_skill( "parry",40 );
        wield_weapon( HWEAPON"comb" );
}

