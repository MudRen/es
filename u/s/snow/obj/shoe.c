inherit ARMOR;

string C_NAME="��Ь";

void create()
{
        set_name("icy shoe", C_NAME);
        add( "id", ({ "shoe" }) );
        set_short( C_NAME );
        set_long(
                "һ˫��Ө�ı�ѩ���ɵ�Ь�ӣ�\n"
        );
        set( "unit", "˫" );
        set( "type", "feet" );
        set( "armor_class", 150 );
        set( "defense_bonus", 150 );
        set("special_defense",(["all":150])) ;
	set( "extra_skill",([ "all":150 ]) );
        set( "weight", 1 );
        set( "value", ({ 1, "gold" }) );
        set( "no_sale", 1);
	set("prevent_drop",1);
}
