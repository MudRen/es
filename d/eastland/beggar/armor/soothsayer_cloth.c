#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("Wind-Fire-Thunder robe","����׵�������");
        add("id",({"robe"}) );
        set_short("����׵�������");
	set_long(@C_LONG
����һ������С�Ϲߴ������ɫ����,���������߿����ձ����������еı�ʯ������
���·����ݺύ�����ɫ�����Ǹ����׾����ݶ�����,����С�ϲ��������渨ʩ����
��,����о���������ӳ����˸�ʽ����������ɫ�ʡ� ����㲻��������������,
Ҳ�����������кܺõ�ħ����������
C_LONG	         );
	set( "unit", "��" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 10 );
	set( "defense_bonus", 5 );
	set("special_defense",
	  (["fire":10,"cold":8,"energy":6,"electric":4,"magic":20]) );
	set( "value", ({ 3465, "silver" }) );
}
