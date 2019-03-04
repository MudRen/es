
#include "../takeda.h"
#include <stats.h>
#include <conditions.h>

inherit SELLER ;
inherit "/std/teacher";
inherit MONSTER ;
inherit DAEMON ;

void init()
{
	::init();
	teacher::init();
	seller::init();
	add_action( "tip_me", "pay");
}

void create()
{
	object bandage;
	int payed;
	::create();
	set_level(8);
        set_name( "Ann Dao Chun", "����ȫ" );
        set_short( "����ȫ" );
	add( "id", ({ "doctor","healer","ann","dao","chun" }) );
	set_long(@C_LONG
�㿴��һ�������ˣ����η����еĴ�磬��������������ҽ����ȫ����������
��ҽ��ͨ���κ�������֢��������ֻ��Ҫ����СǮ�Ϳ��Խ������Ϊ��ɽ����
ר��������ҽʿ��
C_LONG
	);
        set( "race", "human" );
        set( "gender", "male" );
        set_perm_stat( "pie", 25 );
        set_perm_stat( "kar", 20 );
        set_lessons( ([
	"depoison": ({ 150, 80 })
	]) );
	set_perm_stat("int",22);
        set_perm_stat( "dex", 18 );
        set_skill( "dodge", 100 );
        set_skill( "anatomlogy", 85 );
        set_skill( "bandage",90);
	set("defense_type","dodge");
	payed=0;
        set( "aiming_loc", "ganglion" );
        set( "max_hp", 150 );
        set( "hit_points", 150 );
	set_natural_armor( 55, 20 );
        set( "natural_weapon_class1", 25 );
        set( "natural_min_damage1", 10 );
        set( "natural_max_damage1", 20 );
        set( "special_defense", ([ "evil": 30,"none":20]) );
        set( "alignment", 1500 );
        set( "wealth/gold", 30 );

        set( "inquiry", ([
                "heal": "@@ask_heal",
		"clot": "@@ask_clot",
		"cure": "@@ask_cure",
	        "sick": "@@ask_sick",
	        "diet": "@@ask_diet",
	        "bandage": "@@ask_bandage",
	        "sister": "@@ask_sister",
                "da": "@@ask_da",
                "depoison" : "@@ask_depoison"
        ]) );
        set_inventory( ({
                    ({ "/d/eastland/easta/obj/plaster",40,40 }),
                    ({ "/d/eastland/easta/obj/white_plaster",40,40 }),
                    ({ "/d/eastland/easta/obj/spicy_plaster",30,30 }),
                    ({ TOBJ"snow_lily",3,3 })
                    }));
        wield_weapon( TWEAPON"poblade" );
        equip_armor( TARMOR"small_cloth" );
        equip_armor( TARMOR"simple_boots");
          bandage=new("/obj/bandage");
          bandage->move(this_object());
}
    
int I_hate_killer()
{
        if ( this_player() == query_attacker())
        {
        tell_room( environment(), 
        "����ȫŭ��: ���ɵļһ� !! ���һ�����ҽ�� !! ���������ѵ�� ! \n" ,
        this_object() );
        (CONDITION_PREFIX +"simple_poison")->apply_effect(this_player(),8,5);
        return 1;
	}
	return 0;
}

int ask_heal()
{
int num,hpmax,hp;

	if (I_hate_killer()) return 1;
      	command("look "+(string)this_player()->query("name"));
	hpmax=this_player()->query("max_hp");
	hp=this_player()->query("hit_points");
	if (hpmax==hp)
	{
	tell_room( environment(), 
	"����ȫ˵��: ������ܺ�ѽ? \n" ,
	this_object() );
	return 1;
	}
	num=(hpmax-hp)*3;
        if( !this_player()->debit("gold", num) )
        {
        tell_room(environment(), 
	"����ȫҡҡͷ��������Ǯ��̸����\n",
	this_object() );
	return 1;
        }
	tell_room( environment(), 
	"ҽ��˵��������..��Ǯ�ð��£��ó�һƿСҩ��Ϳ������˿��ϣ�һ�������ĸо��ᣬ\n"+
	"��������̺۶�û���¡�\n" ,
	this_object() );
	this_player()->set("hit_points",hpmax);
	return 1;

}
int ask_cure()
{
int num;

	if (I_hate_killer()) return 1;
        command("look "+(string)this_player()->query("name"));
        if ( !this_player()->query("conditions/simple_poison"))
        {
        tell_room( environment(), 
        "����ȫЦ��: ��û���ж���? Ҫ��Ҫ�Ұ���ʩ�㶾?? \n" ,
        this_object() );
        return 1;
	}
        num=25;
       if( !this_player()->debit("gold", num) )
        {
        tell_room(environment(), 
	"����ȫҡҡͷ��������Ǯ��̸����\n",
	this_object() );
	return 1;
        }
        tell_room( environment(), 
        "����ȫ�ó�һ�׺�ɫ�Ĵ̱�ҩˮ��������ı��ӹ�����ȥ����о�ȫ������������\n"+
	"ͷ�ؽ��ᣬ�����ڶ����ƺ�����ʧ�ˡ�\n" ,
        this_object() );
        this_player()->delete("conditions/simple_poison");
        command("say �ڻĽ�Ұ�⣬���������ر�࣬���û��ѧ���ⶾ���ɣ���ò�Ҫ����̽��.......");
        return 1;

}

int ask_clot()
{
int num;

	if (I_hate_killer()) return 1;

        command("look "+(string)this_player()->query("name"));
        if ( !this_player()->query("conditions/bleeding"))
        {
        tell_room( environment(), 
        "����ȫ˵��: ��һ��Ѫ��û����ʡʡ��... \n" ,
        this_object() );
        return 1;
	}
        num=15;
       if( !this_player()->debit("gold", num) )
        {
        tell_room(environment(), 
	"����ȫҡҡͷ��������Ǯ��̸����\n",
	this_object() );
	return 1;
        }
        tell_room( environment(), 
        "ҽ��˵������ !! ���ҽ����Ѩ��ͻȻ�ó�һ��ѽ������������壬�����Ѫ\n"+
	"��ʱֹͣ�ˡ�\n" ,
        this_object() );
        this_player()->delete("conditions/bleeding");
        return 1;
}
int ask_sick()
{
  int num;
     if(I_hate_killer()) return 1;
     command("look "+(string)this_player()->query("name"));
     if (!this_player()->query("condition/sick"))
 {
     tell_room(environment(),
     "����ȫ˵��: ��ܽ���ѽ? ���...\n",
     this_object());
     return 1;
 }
      num=30;
       if( !this_player()->debit("gold", num) )
        {
        tell_room(environment(), 
	"����ȫҡҡͷ��������Ǯ��̸����\n",
	this_object() );
	return 1;
        }
       tell_room(environment(),
       "����ȫ�������ͷ���: ץаץ����ħ������ץаץ����ħ����.....\n"
       "����Ȼͷ�������ˣ����㷢����Ĳ���ȫ�κ��ˣ�\n",
       this_object());
       this_player()->receive_special_damage("none",3);
       this_player()->delete("condition/sick");
       return 1;
}
int ask_diet()
{
command("look "+(string)this_player()->query("name"));
if (!(this_player()->query_temp("fat_quest/fish")) || this_player()->query_temp("fat_quest/fish")<3)
write(
"����ȫ˵��: �㵱���Ǹ�ʲ��İ�??\n");
else {
write(
"\n����ȫ˵��: ���Ƕ�����ҽ�����ǻ������º͵ģ������Ҫ���ټ��ʣ��ҿ���\n"
"�����������Ǽ��������幻�õĻ��������ȥ���Ǹ���ҽ����������һ������\n"
"������ҩร�����ԣ�һ�������������ġ�˵�꣬");
command("grin "+(string)this_player()->query("name"));
return 1;
}
}
int ask_bandage()
{
 int num,hpmax,hp;
	if (I_hate_killer()) return 1;
      	command("look "+(string)this_player()->query("name"));
	hpmax=this_player()->query("max_hp");
	hp=this_player()->query("hit_points");
	if (hpmax==hp)
	{
	tell_room( environment(), 
	"����ȫ˵��: ������ܺ�ѽ? \n" ,
	this_object() );
	return 1;
	}
	if (this_player()->query_temp("bandaged")!=0)
	{
	tell_room( environment(),
	"����ȫЦ��: ���Ѿ����ܹ�����ҽ����.....\n",
	this_object() );
	return 1;
	}
	num=6;
       if( !this_player()->debit("gold", num) )
        {
        tell_room(environment(), 
	"����ȫҡҡͷ��������Ǯ��̸����\n",
	this_object() );
	return 1;
        }
	if( !present("bandage",this_object() ) )
	{
	tell_room(environment(),
	"����ȫ̾������֪������������Ͷ��õ�������������ڳ������ܸ���\n"
	"һЩ�����������ҿ�������Ϊ���ġ�\n",
	this_object() );
	return 1;
	}
	command("bandage "+(string)this_player()->query("name"));
	command("rub "+(string)this_player()->query("name"));
	return 1;

}

int ask_sister()
{
write(
"\n����ȫ˵��: û��������һ�����ã�������С�ۣ����Ե����Ź֣���С�Ͳ�\n"
"̫���ҵĻ���������Ϊ������Ψһ�����ã���Ҳ�����ǳ��ã�ֻ��ż���������\n"
"��һ�죬����һ����������һ�Ŵ����飬���С����С�ͷǳ�ϲ�����飬������\n"
"�ؼҾͰ������͸�����˳������������������֮��Ļ���û�뵽������ҳ���\n"
"��..........���������������.....................\n\n");
call_out("ask_sister2",10,this_player());
return 1;
}
int ask_sister2()
{
write(
"����ȫ̧ͷ������һ�ۣ���˵��: �ǻʸ��˸�����İ�? ������˵����ã�ֻ��\n"
"��ϲ������;˵��˵����Ҫ����ۣ��㻹�ǲ�Ҫ��̫���ϣ��....\n"
"˵�꣬����ȫ����ߴ��������߻ع�̨����ϸһ������������˵ʲ��Ů�Ӻ�����\n"
"�ģ�������˵�Ĳ��岻����������Ҳ��ģ����\n");
this_player()->set_temp("fat_quest/diet",1);
return 1;
}
int ask_da()
{
write (
"����ȫ����һ�£�˵��: ���ʵ���ʯ�ٴ�Ĵ�������? �����������β��õĲ���\n"
"֮һ����ʵ�ϣ�������ֻ��Ӫ���������ѣ�ֻ����Ϊ�������Լ�����ˣ���������\n"
"�Ļ�������ҩ��Ҳ���Է����Ż�������������ӡ�ֻҪ���ϳԷ��ͳ�ҩ�����Ĳ���\n"
"������˵�����������⡣˵�꣬����ȫ�����������¡�\n");
return 1;
}
int ask_depoison()
{
command("say ������ǳ�����Ұ��ð�յĻ����ҵ��ǿ��Խ���һЩ�����Ľⶾ���ɣ�����.......");
return 1;
}

int check_trainee(object trainee)
{
	if( (string)trainee->query("class")=="adventurer" 
	&& (int)trainee->query_level() > 9 && (int)trainee->query_temp("give_money")==1 )
		return 1;
	else
             return notify_fail( 
                    "����ȫ˵��: ��ֻ�̹��ʸ��ð���ߣ������Ը�����һ�����\n" 
                    "����Ļ����Ҿͽ���ⶾ�ķ�����\n");
}
int tip_me(string arg)
{
        string who, type;
        int num;

        if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
                return notify_fail(
                        "��˭������Ǯ��\n");
        if( !id(who ) ) return 0;
        if( type != "gold" ) {
                tell_room( environment(), 
                        "����ȫ˵��: �ú� ! �Բ�����ֻ�ս�ҡ�\n" ,
                        this_object() );
                return 1;
	}
	if ( num < 100 ) {
	tell_room( environment(), 
                 "����ȫ˵��: �ú� ! ��ĳ��ⲻ��ร�\n" ,
                        this_object() );
		return 1;
	}
        tell_room( environment(), 
                 "����ȫ���ͷ��: �ú� ! �����ھ�Ҫ��ʼѧ�ⶾ��(depoison)����\n" ,
                        this_object() );

	this_player()->set_temp("give_money",1);
	return 1;
}

