#include "takeda.h"

inherit ARMOR;

void create()
{
        set_name("License of monks","���");
        add("id",({"license"}) );
         set_short( "a license of monks","���");
	set_long(
"����Ǹ�������ɮ�����ʱ�����������֤����ͨ����������ɮ��ף����\n"
"�ܼᶨɮ�����֮�ģ�\n"
);
	set( "unit", "��" );
	set( "weight", 30 );
	set( "type", "misc" );
	set( "material","monk");
	set( "defense_bonus", 6 );
	set( "no_sale",1);
	set( "value", ({ 250, "gold" }) );
        set( "extra_skills",(["inner-force":8]));
        set( "special_defense",(["evil":30 ,"divine":5]));
}
