inherit WEAPON;

void create()
{
        set_name("Hell Wand","��ڤȨ��");
        add("id",({"wand",}) );
        set_short("��ڤȨ��");
        set_long(@C_LONG
���Ǻڵ�˹�͸�����ڤ���޵�ʿ��Ȩ�ȣ�Ψ�о������صĿ�������õ����
���ȣ�������е��޵�ʿ��ʮ����ϧ��ѵ������׵ķ���
C_LONG
        );
        set( "unit", "��" );
        set( "weapon_class", 35 );
        set("type","wand");
        set( "min_damage", 10 );
        set( "max_damage", 25 );
        set( "weight", 70 );
        set( "value", ({ 1370, "silver" }) );
        set( "power_on", 1);
        set( "hit_func", "wand_hit" );
        set( "charge_left", 10 );
        set( "max_charge", 10 );
        set( "special_damage_type", "evil" );
        set( "special_damage", 40 + random(10) );
        set( "special_c_msg",@LONG
��������ڵ�˹��ħ�����������ħ�����������е��˵����ϣ����
����а������������е����ܵ������ױȵ��˺�
LONG
        );
}
