inherit ARMOR;

void create()
{
        set_name("Purple shield", "�ϻԶ���");
        add( "id", ({ "shield" }) );
        set_short( "�ϻԶ���") ;
        set_long(@LONG 
����һֻ��ɫ�Ķ��ƣ�������л����ͼ�����������ƺ�����
һЩ���ص�������
LONG
	);
	set("unit","��");
        set( "type", "shield" );
	
        set( "material", "light_metal");
        set( "armor_class", 8 );
        set( "defense_bonus", 2 );
        set( "special_defense",
		([ "devine":-10, "fire":10, "evil":-10,
		"cold":-15,"electric":15 ]) );

        set( "weight", 100 );
        set( "value", ({ 300, "gold" }) );
}
