inherit ARMOR;

void create()
{
        set_name("sky plate","���֮��");
        add("id",({"plate"}) );
        set_long(@LONG
�������֮���Թ��ഫ�����ף������֮�������е�����˹���������죬���
�������ʥ�������������ϣ���˳�Ϊʷ����ǿ��ķ���֮һ��\n"
LONG
        );
        set_short( "sky plate","���֮��");
        set( "no_sale",1);
        set( "unit", "��" );
        set( "weight", 140 );
        set( "type", "body" );
	set( "armor_class", 31 );
        set("material","light_metal");
        set( "defense_bonus", 6 ); // ϣ���ܸ�һ�� *��Ϊ������� ac �����*
	set("special_defese",(["cold" :10 ,"fire" : -20," electric": 10 ]) );
        set( "value", ({ 290, "silver" }) );
}
