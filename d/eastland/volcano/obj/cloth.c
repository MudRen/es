#include "../oldcat.h"

inherit OBJECT;

void create()
{
	set_name( "square cloth", "����" );
	set_short( "����" );
	set_long(
"����һ��Լ�����߼�����Ĳ������滹������\��ͼ���������������������ɾ���\n"
	);
        add( "id", ({"cloth"}) );
	set( "no_sale", 1 );
	set( "unit", "��" );
	set( "weight", 2 );
	set( "value", ({ 1, "silver" }) );
}
