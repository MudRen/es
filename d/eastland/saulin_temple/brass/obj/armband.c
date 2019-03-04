#include <mudlib.h>

inherit ARMOR;
 
void create()
{
        set_name("brass armband", "�ۻ�");
        add( "id", ({"armband" }) );
        set_short("���������ۻ�");
        set_long(
                "����һ����ʮ�˸���̬ׯ�ϵ��޺��ۺ϶��ɵıۻ�������ʩչ��\n"
                "һ�ײ�ͬ��ȭ����\n"
        );
        set( "unit", "��");
        set( "type", "arms" );
        set( "material", "monk" );
        set( "defense_bonus",1 );
        set( "armor_class",1 );
        set( "weight", 1 );
        set( "value", ({ 1, "gold" }) );
        set( "no_sale",1);
        set( "prevent_drop",1);
        set( "extra_skills", (["inner-force":5,"recitation":10]) );
        set( "equip_func", "to_equip");
        set( "unequip_func", "to_unequip");
}

int query_auto_load() { return 1; }

int to_equip() 
{
	this_object()->set("extra_look","@@looks");
	return 1;
}
int to_unequip()
{
	this_object()->delete("extra_look");
	return 1;
}
string looks()
{
	return set_color("$N����һ������ʮ���޺��ıۻ�, \n��������ͨ��������ʮ��ͭ�����֤����, ����ǿ�ߵ����� !!\n","HIW");
}