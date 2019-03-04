#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Master Tenshin", "���Ĵ�ʦ" );
	add( "id", ({ "monk", "tenshin", "master", }) );
	set_short( "���Ĵ�ʦ" );
	set_long(
@LONG_DESC
�㿴��һλ��ü��Ŀ���Ϻ��У�������ҩ����ĳ��ϣ����Ĵ�ʦ����ʦ����Ѿ�
�����ˣ�������������е���������Ȼ��������������Ȥ��������ҽҩ�Լ���
���ˣ�Ҳ�������ͨ������Ѫ֮������ʦ�ĵ�Ѩ��\��ھ����֣���ʱ�������ɶ�
�����������档�������������ҩ��(herb)����Ŀ��
LONG_DESC
	);
    set( "inquiry", ([
         "herb" : 
@HERB
�����ӷ�! ʩ��������֪����������쳣��ҩ���еĻ����ݾ�
              ȻǬ��\�����������������ƾ�ת������ı���ҩ����Ǽ���
              �õľȼ�����ҩ��ʵ����һ�ղ��ɻ�ȱ�������ļ����ƫ�ֲ�
              ���糱��ʵ��û��ʱ��ȥѰ�����ǵõ�ʱ����������ɽ��ֲһ
              �꣬��֪��������ˣ��ɷ���ʩ��ǰ��һ̽���������Ҵ�
              �鷳ʩ�������ƻ�ҩ�ԣ���������ͬ�д��! �����ӷ�...
HERB
	     ,
	"heal" : "@@ask_heal",
]));
	set("race", "human");
	set("gender", "male");
	set_perm_stat("int", 30);
	set_perm_stat("str", 25);
	set_perm_stat("dex", 30);
	set_skill("dodge", 100);
	set_skill("dagger", 100);
	set_skill("anatomlogy", 100);
	set("aiming_loc", "weakest");
	set("max_hp", 987);
	set("max_fp", 543);
	set("force_points", 543);
	set("hit_points", 987);
	set_natural_armor( 50, 40 );
	set_natural_weapon( 5, 15, 25 );
	set("special_defense", ([ "all": 50, "none":30 ]) );
	set("aim_difficulty", ([ "critical" : 50, "vascular" : 50, ]) );
	set("alignment", 1500);
	wield_weapon( SAULIN_OBJ"holy_dagger2" );
	equip_armor( SAULIN_OBJ"cloth2" );
	equip_armor( SAULIN_OBJ"boot2" );
}

void init()
{
	::init();
	add_action("report_master","report");
}

int tired(object who)
{
        tell_room( environment(), 
        "���Ĵ�ʦ���˹�\������������������ʮ�� !!\n" ,
        this_object() );
        set("tired",0);
        return 1;
}

int check_tired()
{
        if ((int)this_object()->query("tired")==1)
        {
        tell_room( environment(), 
        "���Ĵ�ʦ�����˹�\������ñ��� !!\n" ,
        this_object() );
        return 0;
	}
        return 1;
}

int I_hate_killer()
{
        if ( this_player() == query_attacker() || (this_player()->query_temp("saulin_killer")) ) 
        {
        tell_room( environment(), 
        "���Ĵ�ʦ��ʮ��: ʩ������Ѫ�ȣ��뼰���ͷ��ˡ��ɮ��������ΪŰ !!\n",
        this_object() );
        return 1;
	}
        return 0;
}
int check_quest()
{
        if (this_player()->query("quest/Tenshin's_herb"))
        return 1;
        tell_room( environment(), 
		"���Ĵ�ʦ��ʮ������������ɮ���ϰ��㣬������ɮ�������� !! ��ʩ������ !��\n"
	,this_object() );
        return 0;
}
int ask_heal()
{
	int num,hpmax,hp;

        if (!check_tired()) return 1;
        if (query("hit_points") < query("max_hp"))
        {
        tell_room( environment(), 
        "���Ĵ�ʦЦ��: �ף���ɮʲ��ʱ���ܵ��ˣ��Ͽ����� !! ... \n"
        "����������ʼ�˹�\���ˡ�\n",
        this_object() );
        set("hit_points",query("max_hp"));
        set("tired",1);
        call_out("tired", 300+random(90),this_object());
        return 1;
	}
        if (I_hate_killer()) return 1;
        if (!check_quest()) return 1;
        command("look "+(string)this_player()->query("name"));
        hpmax=this_player()->query("max_hp");
        hp=this_player()->query("hit_points");
        if (hpmax==hp)
        {
        tell_room( environment(), 
        "���Ĵ�ʦЦ��: ����ʩ�����ܽ����� ... \n" ,
        this_object() );
        return 1;
	}
        num=(hpmax-hp)*2;
       if( !this_player()->debit("gold", num) )
        return notify_fail(
        "��ͻȻ��������û���㹻������Ǯ... ������˼�������ʦҽ��\n");

        tell_room( environment(), 
        "���Ĵ�ʦ˵�������� !! ��ʩ������ !������˫�ִ�����ı��ģ���ͻȻ�е�\n"
        "����ǿ����������ʼ����ȫ��ɲʱ�����ȫ��˵�������泩��\n"
	"��Ц����Ŀ����㣬Ȼ��ͷһ�㣬�� �� �붨�� ����\n" ,
        this_object() );
        this_player()->set("hit_points",hpmax);
	tell_object(this_player(),
	"Ϊ�˸�л��ʦ�����ͣ���ܳ��ĵľ���Щ����Ǯ��\n" );
        set("tired",1);
        call_out("tired", 300+random(90),this_object());
        return 1;

}

int report_master(string arg)
{
	string who, type;
	
    if( !arg || (sscanf(arg, "%s to %s", type, who) != 2) )
    	return notify_fail( 
    	  "�ر�ʲ���¸�(to)˭��\n" );
    if( !id(who) )
    	return notify_fail(
    	  "��Ҫ��˭���氡! ����û�����\n" );

	if( type=="herb" ) {
        tell_object( this_player(), @REPORT
        
���Ĵ�ʦ˵: �����ӷ�! ��������! ʩ���˾��������츣���񣬱������м���
            ΢��ȫ��ʩ��֮��\��ֻ��������һ�²���������������Ѹ�٣���
            ��������֮���\����������ҩ����֮ˮ���ֺ���һҹ��Ǭ�Լ���
            �������������˲��⣬ʩ�����˿ɷ�ǰ��һ̽(explore)��
			
REPORT
        );
	return 1;
	}
	if( type=="mushroom" ) {
		tell_object( this_player(),@MUSHROOM
		
���Ĵ�ʦ˵: �����ӷ�! ��������! ԭ����ˣ�������ɽ���������֥��
            ���������ֶ��ӣ��ѵ��ҵȾ�����һ��֮ˮ�𣿸��ο�������
            ����֮�£��������ǰ���춴˰�! ���֮ˮ����������취��
            ���� !! ��лʩ������ !! ����ʩ��������Ҫҽ��(heal)��ɮ
	    ԸЧ�ౡ֮����
			
MUSHROOM
        );
		return 1;
	}
	return 1;
}

