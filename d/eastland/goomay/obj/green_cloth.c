#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("green cloth","������");
        add("id",({"cloth","green"}) );
        set_short("green cloth","������");
	set_long(
"This is a suit of cloth made of silk meterial.\n",
"���µƺ����꣬���񰵸��̣����˽����𣬼��ȸ�ɽ������ \n"  
"�����ý��ϵĴ��˿�ͺ���ɽׯ�ĺ��̳��֯���ɵ����ѡ� \n"   
"�ǡ�����һ���������͸�����Ķ���֮�Ȼ��ˮ���飬�仨����... \n"
	);
	set( "unit", "��" );
	set( "weight", 135 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 20 );
	set( "defense_bonus", 10 );
	set( "value", ({ 250, "gold" }) );
	set("no_sale",1);
}
