#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black platemail", "��ɫ����" );
	add( "id", ({ "plate", "platemail" }) );
	set_short( "��ɫ����" );
	set_long(@AA
����һ�׺ͺ�ɫ��ϥ��ͬ���ϵĿ��ף���������Ȼ�����ۣ�ȴ���ṩ�൱����ķ�������
AA
	);
	set( "unit", "��" );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 33 );
	set( "equip_func","bonus_up");
	set( "unequip_func","stop_bonus_up");
	set( "weight", 270 );
	set( "value", ({ 2000, "silver" }) );
}
void bonus_up()
{
    object ob;
    if((ob=present("wooden armband",environment(this_object()) ))&&
        (ob->query("equipped"))){
        set( "defense_bonus",6);
        set( "armor_class",35);
        tell_object(environment(this_object()),
"���㴩�Ϻ�ɫ����ʱ���������ͺ�ľ�ۻ������ܺ��γ�һ�׼�����ս����\n"
);
return 0;
}
}
void stop_bonus_up()
{
set( "defense_bonus",0);
set( "armor_class",33 );
}
