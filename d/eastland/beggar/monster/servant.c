#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(12);
	set_name( "servant", "С��ͯ" );
	add( "id",({"servant"}) );
	set_short( "С��ͯ" );
	set_long(@C_LONG
С��ͯ��ؤ�����ǲ�����λ���ŵ�,��ר���̺������ 
C_LONG	
        );
        set( "unit", "��" );
	set_perm_stat( "str", 16 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "kar", 15 );
	set_skill( "dodge", 40 );
	set( "special_defense", ([ "all": 20 ]) );
	set( "race","human");
	set( "gender", "male" );
	set( "alignment", 0 );
	set_natural_armor(15, 7 );
	set_natural_weapon( 10, 3, 5 );
	set( "wealth/gold", 20 );
        wield_weapon(DWEAPON"blade");
}
