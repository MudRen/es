#include <../goomay.h>
inherit MONSTER ;

void create()
{
	::create();
	set_level(16);
        set_name( "Old doctor", "��ҽ��" );
        set_short( "��ҽ��" );
	add( "id", ({ "doctor" }) );
	set_long(
@C_LONG
�㿴��һ����ͺܴ����ҽ����������ɫ��üë�����Ĵ����۾������࣬
���е��۾��������쿴���������ˣ����ƺ���Щ��Ϳ������Ƣ��ȴǿ��
�ܣ�����Ĵ����Ǯ�����Ŵγ��߼�Ҫ��������ҩ�̣���˵ʲ��Ҳ���ã�
�治֪�����ǲ��ǵ�������մ�֢��
C_LONG
	);
        set( "race", "human" );
        set( "gender", "male" );
        set_perm_stat( "int", 26 );
        set_perm_stat( "kar", 20 );
	set_perm_stat("str",25);
	set_perm_stat("con",25);
        set_perm_stat( "dex", 25 );
        set_skill( "dodge", 100 );
        set_skill( "dagger", 75 );
        set_skill( "anatomlogy", 80 );
	set("defense_type","dodge");
        set( "aiming_loc", "weakest" );
        set( "max_hp", 500 );
        set( "hit_points", 500 );
	set_natural_armor( 55, 20 );
        set( "natural_weapon_class1", 15 );
        set( "natural_min_damage1", 2 );
        set( "natural_max_damage1", 12 );
        set( "special_defense", ([ "all": 40,"none":20]) );
        set( "alignment", 1500 );
        set( "wealth/gold", 50 );

        set( "inquiry", ([
                "heal":  "@@ask_heal",
		"hunter" : "@@ask_hunter",
		"jor" : 
@LEG
�� !! �����ȵ��˰� ���� ���ˣ�ǰ����ҹ����һ��������
�������ң�����˫���ȹǶ��������ˣ���������Ȼ�����Լ�����������һ�糣
�ˣ��Ҿ������������Ṧ\���֣����������Ʋ��Ϸ�֮����Ṧ\�����Ұ����Ӻ�
����֮���������ˣ�û�л�����������������״������������֮����ǿ���˹�\
���У���Ȼ���ҽӹǣ���Ҫ��סһ���Ṧ\��ʧ������Ҫ��Ϣ��������ϣ�����
���߲�Զ������ !! �������Ժ����������(wu)������ץ�ν�����˵�ҩ����
֪��������û�й�ϵ��
LEG
        ]) );
        wield_weapon( Obj"silvery_dagger" );
        equip_armor( Obj"healer_robe" );

}

int accept_item(object me,object item)
{
	object ob1;
     if ((string) item->query("name") !="amaze root" )
        {
     tell_object(me,
        "��ҽ��ҡҡͷ����лл !! �Ҳ���Ҫ�ⶫ�� !!��\n");
	command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
        return 1;
	}
     tell_object(me,
@MISSION
��ҽ���ӹ�ҩ�ݣ�����ϸ�Ŀ�����Ȼ������ĵ��ͷ���Ϳ�ʼ��ץ��ץ������
ҩ����ֻ����һ���۵Ĺ�\\�����Ͱ����˼�����ҩ��������ҩ���ݸ��㣬Ȼ��
�����������⼸��ҩ������Ӧ�þͿ����𴲻�ˣ��Ͽ������ȥ�� !!��
MISSION
        );
        ob1 = new( Obj"drug_pack" );
	ob1->move(this_object());
        command("give "+(string)ob1->query("name")+" to "+lower_case((string)me->query("name")));
        return 1;
}

int ask_hunter()
{
	if ( (int)this_player()->query_quest_level("Goddess_statue") > 0 )
	tell_object(this_player(),
	"��ҽ��ɦɦͷ˵����˭�ֲ��ˣ��Ҽǵ��Ҹ�����ҩ�˰� !!��\n");
	else
        tell_object(this_player(),
	"��ҽ��̾�������������˰����Ĳ��Һ������������ȱ��һζ��ҩ�����컨�ĸ�\n"
	"(root)��˵������������˼��ã�������ͷ���Ҽ��������� !!��\n");
		return 1;
}

int tired(object who)
{
	tell_room( environment(), 
	"��ҽ�����˸���Ƿ����������������������ö��� !!\n" ,
	this_object() );
        set("tired",0);
        return 1;
}

int check_plaster()
{
	if ((int)this_player()->query_quest_level("Goddess_statue") > 0)
	return 1;
        tell_object(this_player(), 
        "��ҽ��ͷҲ���ص�˵��������ûҩ������׼�����Ų�ҩ�� ! ��Ǹ�� !!��\n");
	return 0;
}
int check_tired()
{
        if ((int)this_object()->query("tired")==1)
	{
        tell_object(this_player(), 
        "��ҽ����������ƣ�ͣ����ڴ������ñ��� !!\n" );
        return 0;
	}
	return 1;
}
int I_hate_killer()
{
        if ( this_player() == query_attacker())
        {
        tell_object(this_player(), 
        "ҽ��ŭ��: ��Ҫ�������� !! ���һ�����ҽ�� !! ���д��� ! \n" );
        return 1;
	}
	return 0;
}

int ask_heal()
{
int num,hpmax,hp;

	if (!check_tired()) return 1;
	if (query("hit_points") < query("max_hp"))
	{
        tell_room( environment(), 
        "ҽ��˵��: ��ѽѽ !! ��ʲ��ʱ���ܵ��ˣ��Ͽ��һ�� !! ... \n"
	"����ʼ��æ���ҵİ����Լ���ͻȻ��ͷһ�㣬�� �� ˯���� ����\n",
        this_object() );
	set("hit_points",query("max_hp"));
        set("tired",1);
        call_out("tired", 300+random(90),this_object());
        return 1;
	}
	if (I_hate_killer()) return 1;
        if (!check_plaster()) return 1;
	command("look "+(string)this_player()->query("name"));
	hpmax=this_player()->query("max_hp");
	hp=this_player()->query("hit_points");
	if (hpmax==hp)
	{
	tell_object( this_player(), 
	"ҽ��˵��: �ҿ�����ͷ�������� !! ��ˣ�� ... \n" );
	return 1;
	}
	num=(hpmax-hp)*2;
       if( !this_player()->debit("gold", num) )
        return notify_fail( 
	"ҽ��ҡҡͷ��������û��������� !! ����ɲ��������\n");

	tell_object( this_player(), 
	"ҽ��˵�������� !! ���ҵ� !��������������һ�����ص����ģ���ͻȻ�е�\n"
	"ȫ�������档��Ц����Ŀ����㣬ͻȻ��ͷһ�㣬�� �� ˯���� ����\n" );
	this_player()->set("hit_points",hpmax);
	set("tired",1);
	call_out("tired", 300+random(90),this_object());
	return 1;

}
