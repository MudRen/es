#include "../dony.h"

inherit ARMOR;

void create()
{
        set_name("black cloth","��ɫ������");
        add("id",({"cloth"}) );
        set_short("��ɫ������");
	set_long(@C_LONG
����һ����ɫ���·�,��Ȼ�������ܽ�, ȴ������ж��������Ƕ��ĳЩ�������
ҵ,�ж��ܸ�����������õʤ�����ء� 
C_LONG	         );
	set( "unit", "��" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","thief");
	set( "armor_class", 15 );
	set("special_defense",
	     (["evil":15,"divine":-20]) );
	set( "value", ({ 1480, "silver" }) );
}
