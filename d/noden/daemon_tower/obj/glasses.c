#include <mudlib.h>

inherit ARMOR;

void create()
{
#include <compress_obj.h>
	set_name( "glasses", "ī��" );
	set_short( "ī��" );
	set_long(
		"����һ���������ī�������Ե�סǿ������䡣\n"
	);
	set( "unit", "��" );
        set("material","element");
	set( "type", "head" );
	set( "weight", 20 );
	set( "armor_class", 2 );
	set( "value", ({ 40, "silver" }) );
        set( "extra_look", "$N����һ���������ī�����Ե�ʮ��˧����\n" );

}
