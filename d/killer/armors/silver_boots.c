#include  <mudlib.h>

inherit ARMOR;

string C_NAME="���˿Ь";

void create()
{
        set_name("silver boots", C_NAME);
        add( "id", ({ "boots" }) );
	set_short( C_NAME );
        set_long(
                "һ˫��������ɫѥ�ӣ���˫ѥ����ŵ���������ҵ���Լ�������\n"
                "�����ľ��Ľ��������������Ժ���������˵������˫ѥ�ӵķ���\n"
                "�����˸���ħ�����⣬�Ѿ��޷��ٸ�ǿ�ˡ�\n"
        );
        set( "unit", "˫" );
        set( "type", "feet" );
        set( "material", "knight");
        set( "extra_skills", ([ "defend":10 ]) ); 
        set( "armor_class", 10 );
        set( "weight", 50 );
        set( "value", ({ 100, "gold" }) );
        set( "no_sale", 1); 
}
