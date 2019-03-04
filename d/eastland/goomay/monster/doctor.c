#include <../goomay.h>
#include <stats.h>
#include <move.h>
inherit MONSTER ;
inherit DAEMON ;

string *c_msg = ({
"��ҽ��˵ ����ʲ�᣿�����ҿ�û�а�����\n",
"��ҽ��˵ ����Ҫ���ﰡ��������ز����Ϸ���ඣ����������ˣ��� ..\n"+
  "����һ�� ... �ð� !! ���· !! �Ϸ������������û��Լ������ġ���\n" ,
"��ҽ��˵ ����˭��С������������ !! û���������� !!��\n",
"��ҽ��˵ �������� !! �۾��ſ�.. �� ...�������.. �����������������ˡ�\n",
"��ҽ��˵ ������˵ʲ�᣿��\n",
"��ҽ��˵ �����������ʰ� !! �����˼��ⲻ�Ǹ��������𣿡�\n",
"��ҽ��˵ ������ !! �Ҽǵ����С�ҵĲ����Ǻ�������ˣ�Ұ� !!��\n",
});
string *msg = ({
"The Doctor says : What ?? you get sick ?? Hmm.. I don't think so ...\n",
"The Doctor says : Goto help others ? ok !! I will follow you ! \n",
"The Doctor says : Who take baby ?? Oh ! no ! I am no more young ..\n",
"The Doctor says : well !! your eyes .. open .. good ..ears .. WAAAAAAA\n",
"The Doctor says : Excuse me ??\n",
"The Doctor says : Okok ! I am coming !! don't ask same question all the way\n",
"The Doctor says : Hmm .. I remember Fishman is pretty health now !! \n",
});

void create()
{
	::create();
	set_level(16);
        set_name( "Old doctor", "��ҽ��" );
        set_short( "Old doctor", "��ҽ��" );
	add( "id", ({ "doctor" }) );
	set_long(
		"You see a very old doctor.\n",
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
        set( "aiming_loc", "ganglion" );
        set( "max_hp", 400 );
        set( "hit_points", 400 );
	set_natural_armor( 55, 20 );
        set( "natural_weapon_class1", 25 );
        set( "natural_min_damage1", 10 );
        set( "natural_max_damage1", 20 );
        set( "special_defense", ([ "all": 30,"none":20]) );
        set( "alignment", 1500 );
	set("pet_master","xxyyxx");
        set( "wealth/gold", 50 );

        set( "inquiry", ([
                "out" : "@@ask_out",
                "heal": "@@ask_heal",
		"clot": "@@ask_clot",
		"cure": "@@ask_cure",
		"jor" : ({ "EMPTY.\n",
@LEG
�� !! �����ȵ��˰� ���� ���ˣ�ǰ����ҹ����һ��������
�������ң�����˫���ȹǶ��������ˣ���������Ȼ�����Լ�����������һ�糣
�ˣ��Ҿ������������Ṧ\���֣����������Ʋ��Ϸ�֮����Ṧ\�����Ұ����Ӻ�
����֮���������ˣ�û�л�����������������״������������֮����ǿ���˹�\
���У���Ȼ���ҽӹǣ���Ҫ��סһ���Ṧ\��ʧ������Ҫ��Ϣ��������ϣ�����
���߲�Զ������ !! �������Ժ����������(wu)������ץ�ν�����˵�ҩ����
֪��������û�й�ϵ��
LEG
		})
        ]) );
        wield_weapon( Obj"silvery_dagger" );
        equip_armor( Obj"healer_robe" );

}

void relay_message(string class1, string msg)
{
        string who,dir,master;
master=(string)this_object()->query("pet_master");

if( sscanf( msg, "%s leaves %s.\n", who,dir )==2 && lower_case(who) == master)
        {
        command("go "+lower_case(dir));
        if ((string)environment(this_object())->query("c_short")=="�����С��")
	{
        tell_room( environment(), ({
        "The Doctor begin to diagnose for the poor fishman ....\n"+
	"After he finish his job, he says : He is in dangerous , you save his life\n"+
	"and he will recover . \n",
        "��ҽ��һ����������ǰȥ��ʼΪ��������������Ȼ���ü�����ַ�ȡ��\n"+
	"��ö���������������ϣ���Ϊ�����������ķΰ�Ħ����Ȼ����򷢳���\n"+
	"�������������Ĵ��޾��Ļ��������˹�����ҽ���û���������ζҩ��һ��\n"+
	"��ͷ����˵�����������㣬��Ȼ������С���ͱ����ˣ����������������\n"+
	"��Σ�գ����Ĳ����ǲ����Σ���������̫�����ˣ�����ҩ�����׷��ӣ���\n"+
	"Ҫ�ú��չ������һ᳣�����������ġ�˵�꣬������һЩҩ��˵���˷���\n"+
	"�ķ���������ˡ�\n" }),
        this_object() );
        tell_object(this_player(),can_read_chinese() ?
        "������������չ˲��ˣ������ϸ�������£����Ҳ�����Ļָ�������\n"+ 
	"������ʮ�ָм���Ը����ʱ������Ĳ�ǲ !! \n" :
	"So you stay and take care the fishman . under your care , the fishman recover \n"+
	"very well and want to do anything for you . ");

        this_player()->set("goomay/fishman",1);
        set("pet_master","xxyyxx");
        set("tired",1);
        call_out("tired", 120,this_object());
        this_object()->move(Goomay"plaster_shop");

	}
        return;
	}
        return;
}

int tired(object who)
{
	tell_room( environment(), ({
	"The Doctor wake up and look not so tired.\n",
	"��ҽ�����˸���Ƿ����������������������ö��� !!\n" }),
	this_object() );
        set("tired",0);
        return 1;
}

int back_home(object who)
{
	tell_room( environment(), ({
	"The old Doctor sighs and says : I am too old !! need some rest .\n",
	"��ҽ����Ц��˵�������� ! ��ͷ������ !! �û�ȥ��Ϣ��Ϣ���������Լ���ȥ�ˡ�\n" 
	}),this_object() );

        set("pet_master","xxyyxx");
	set("tired",1);
	call_out("tired", 300,this_object());
        this_object()->move(Goomay"plaster_shop");
        return 1;
}
int check_plaster()
{
	if (this_player()->query_temp("green_pearl") 
	    || this_player()->query("goomay/fishman"))
	return 1;
        tell_room( environment(), ({
        "The old Doctor sighs and says : I hope I can help you .. but I need herb.\n",
        "��ҽ����Ц��˵������������ͷ�Ӳ��ϰ��㣬���ǵ���ûҩ����һ��취Ҳû�С���\n"
	}),this_object() );
	return 0;
}
int check_tired()
{
        if ((int)this_object()->query("tired")==1)
	{
        tell_room( environment(), ({
        "The Doctor looks very tired and fall asleep ! please don't wake him.\n",
        "��ҽ����������ƣ�ͣ����ڴ������ñ��� !!\n" }),
        this_object() );
        return 0;
	}
	return 1;
}
int I_hate_killer()
{
        if ( this_player() == query_attacker())
        {
        tell_room( environment(), ({
        "The doctor says: Damn !! You ask me heal such a killer like you ? \n",
        "ҽ��ŭ��: ��Ҫ�������� !! ���һ�����ҽ�� !! ���д��� ! \n" }),
        this_object() );
        return 1;
	}
	return 0;
}

int ask_out()
{
	int i;
	string who;

	if (!check_tired()) return 1;
	if (I_hate_killer()) return 1;
	if (!check_plaster()) return 1;
        i=random(5);
	who=(string)this_player()->query("name");
        if ((string)this_object()->query("pet_master") == who)
	{
		tell_object(this_player(),can_read_chinese() ?
			    c_msg[5] : msg[5]);
		return 1 ;
	}

	tell_object(this_player(),can_read_chinese() ?
		    c_msg[i]: msg[i]);

		if (i==1)
		{
		if (this_player()->query("goomay/fishman"))
			tell_object(this_player(),can_read_chinese() ?
				    c_msg[6]: msg[6]);
		else
		{
			set("pet_master",who);
			call_out("back_home", 30,this_player());
		}
		return 1 ;
		}
		return 1 ;
}

int ask_heal()
{
int num,hpmax,hp;

	if (!check_tired()) return 1;
	if (query("hit_points") < query("max_hp"))
	{
        tell_room( environment(), ({
        "The doctor says: Sorry !! I must heal myself first.\n",
        "ҽ��˵��: ��ѽѽ !! ��ʲ��ʱ���ܵ��ˣ��Ͽ��һ�� !! ... \n"+
	"����ʼ��æ���ҵİ����Լ���ͻȻ��ͷһ�㣬�� �� ˯���� ����\n"}),
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
	tell_room( environment(), ({
	"The doctor says: You are pretty health.\n",
	"ҽ��˵��: �ҿ���ͷ�������� !! ��ˣ�� ... \n" }),
	this_object() );
	return 1;
	}
	num=(hpmax-hp)*2;
       if( !this_player()->debit("gold", num) )
        return notify_fail( can_read_chinese()?
	"ҽ��ҡҡͷ��������û��������ҡ���\n": 
	"The doctor shakes his head and say  :You don't have that many gold coins.\n" );

	tell_room( environment(), ({
	"The doctor says: ok !! let me heal you ... he utter a strange word\n"
	"and you feel all your wound are cured !!\n",
	"ҽ��˵�������� !! ���ҵ� !��������������һ�����ص����ģ���ͻȻ�е�\n"+
	"ȫ�������档��Ц����Ŀ����㣬ͻȻ��ͷһ�㣬�� �� ˯���� ����\n" }),
	this_object() );
	this_player()->set("hit_points",hpmax);
	set("tired",1);
	call_out("tired", 300+random(90),this_object());
	return 1;

}
int ask_cure()
{
int num;

        if (!check_tired()) return 1;
	if (I_hate_killer()) return 1;
        if (!check_plaster()) return 1;
        command("look "+(string)this_player()->query("name"));
        if ( !this_player()->query("conditions/simple_poison"))
        {
        tell_room( environment(), ({
        "The doctor says: You are pretty health.\n",
        "ҽ��˵��: �ҿ���ͷ�������� !! ��ˣ�� ... \n" }),
        this_object() );
        return 1;
	}
        num=20;
       if( !this_player()->debit("gold", num) )
        return notify_fail( can_read_chinese()?
        "ҽ��ҡҡͷ��������û��������ҡ���\n":
        "The doctor shakes his head and say  :You don't have that many \n"+
	"gold coins.\n" );

        tell_room( environment(), ({
        "The doctor says: ok !! let me heal you ... he utter a strange word\n"
        "and you feel your poison are cured !!\n",
        "ҽ��˵�������� !! ���ҵ� !����ȡ����֧����ɿ���������Ѩ���ϣ���е�\n"+
	"���ڶ����������ʧ����Ц����Ŀ����㣬ͻȻ��ͷһ�㣬�� �� ˯���� ����\n" }),
        this_object() );
        this_player()->delete("conditions/simple_poison");
        set("tired",1);
        call_out("tired", 240+random(60),this_object());
        return 1;

}

int ask_clot()
{
int num;

        if (!check_tired()) return 1;
	if (I_hate_killer()) return 1;
        if (!check_plaster()) return 1;

        command("look "+(string)this_player()->query("name"));
        if ( !this_player()->query("conditions/bleeding"))
        {
        tell_room( environment(), ({
        "The doctor says: You are pretty health.\n",
        "ҽ��˵��: �ҿ���ͷ�������� !! ��ˣ�� ... \n" }),
        this_object() );
        return 1;
	}
        num=10;
       if( !this_player()->debit("gold", num) )
        return notify_fail( can_read_chinese()?
        "ҽ��ҡҡͷ��������û��������ҡ���\n":
        "The doctor shakes his head and say  :You don't have that many gold coins.\n" );

        tell_room( environment(), ({
        "The doctor says: ok !! let me heal you ... he utter astrange word\n"
        "and you feel your bleeding have stop !!\n",
        "ҽ��˵�������� !! ���ҵ� !����ϸ�ĵ�Ϊ������˴������ʧѪ������\n"+
	"ֹͣ�ˡ���Ц����Ŀ����㣬ͻȻ��ͷһ�㣬�� �� ˯���� ����\n" }),
        this_object() );
        this_player()->delete("conditions/bleeding");
        set("tired",1);
        call_out("tired", 240+random(60),this_object());
        return 1;

}
