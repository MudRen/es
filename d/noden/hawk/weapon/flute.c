inherit WEAPON;

void create()
{
        set_name("gold flute","��ɫ����");
        add("id",({"flute",}) );
        set_short("��ɫ����");
        set_long(@C_LONG
����һ�ѷ�����ɫ��â���������ѡ�
C_LONG
        );
        set( "unit", "��" );
	set( "weapon_class", 35 );
        set("type","blunt");
        set( "min_damage", 12 );
        set( "max_damage", 25 );
        set( "weight", 80 );
        set( "value", ({ 4000, "silver" }) );
}
