#include <mudlib.h>
inherit WEAPON;
 
void create()
{
        set_name("feather fan", "����");
        add ("id",({ "fan","wand",}) );
        set_short("����");
        set_long(
        "����һ֧����ƽ�������ȣ����������������Ĵʣ������ڽ�̸Ц�䣬\n"
        "ǿ²�ҷ�����....Ҳ����ֻ����Ҳ���������ħ��...��\n"
        );
        set( "unit", "֧" );
        set( "weapon_class", 35 );
        set( "type", "wand" );
        set( "min_damage", 18 );
        set( "max_damage", 27 );
        set( "weight", 40 );
        set( "power_on", 1);
        set( "no_sale", 1);
        set( "value", ({ 7000, "silver" }) );
        set( "hit_func", "wand_hit" );
        set( "charge_left", 7 );
        set( "max_charge", 7 );
        set( "special_damage_type", "electric" );
        set( "special_damage", 60 );
        set( "special_c_msg", "һ�ӣ��г�һƬ���ƣ�����һ��ǿ��ĵ��꣬���ŵ�һ�ɽ�ζ��");
}
