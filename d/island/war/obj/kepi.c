#include <mudlib.h>

inherit ARMOR;
void create()
{
        set_name( "Kepi","��ñ" );
        add( "id",({ "kepi" }) );
        set_short( "��ñ" );
	set_long( @LONG
	һ��ƽ���ľ�ñ��
LONG
		);
        set( "unit","��" );
        set( "type","head" );
        set( "material","cloth" );
        set( "armor_class",4 );
        set( "defense_bonus",2 );
	set( "weight",30 );
	set( "value",({ 320,"silver" }) );
}

