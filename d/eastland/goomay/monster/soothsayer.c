#include <mudlib.h>

inherit MONSTER;

void init()
{
	::init();
		add_action( "tip_me", "pay");
        add_action( "ask_me", "ask");
}

int payed;
void create()
{
        ::create();
        set_level( 12 );
	set_name( "soothsayer", "������֪" );
	add( "id", ({ "man" }) );
        set_short( "������֪" );
        set_long(
@LONG
    �����ǽ����ϴ��������ġ�������֪����һ����������է��֮�¾�����
һ�����صĵ���ѧ����ֻ�д����Ƕ�΢����������ż������ľ����ʹ���
���������죬��˵�����ܹ�֪��ȥδ����������ȴ���ٽ��ܽ����˵�ί�в�
�ԣ�������ʮ��ǰ������ǰ�������ִ������Ԥ��ȴʹ�˼�����̡�
LONG
        );
        set( "gender", "male" );
	set("race","human");
	payed=0;
        set( "alignment", 300 );
        set_natural_armor( 70, 25 );
        set_natural_weapon( 21, 10, 20 );
        set_perm_stat( "str", 25 );
        set_perm_stat( "kar", 18 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "dex", 25 );
        set_skill( "dodge", 100 );
        set_skill( "unarmed",100);
        set_skill( "target",60);
        set_skill( "concentrate",60);
        set_skill( "black-magic",60);

        set( "tactic_func", "my_tactic" );
        set ("defense_type","dodge");
        set("spell_levels/black_magic",15);
        set( "spells/ether-bolt",2);
		set("spell_power",0);
        set( "max_sp",500);
        set( "spell_points",500);
        set( "hit_points", 450 );
        set( "max_hp", 450 );
        set( "special_defense", ([ "all": 30 ]) );
        set( "wealth/gold", 20 );
}

int ask_me(string str)
{
        string mon_name,subject;

        if (!str)
                return notify_fail( 
                "Ҫ�ʷ������������⣬���� \"ask <˭> about <�ؼ���>\"��\n");

        if (sscanf(str, "%s about %s", mon_name, subject) != 2)
                return notify_fail(
                "Ҫ�ʷ������������⣬���� \"ask <˭> about <�ؼ���>\"��\n");
        if (mon_name!="soothsayer")
        {
                this_player()->command("ask "+str);
                return 0;
		}
        if (!payed) {
                write(
                "������֪��������һ�ιҽ������һ������ !! ���ǹ�� !! �� \n" );
                return 1;
		}

switch (subject) {
        case "goddess" :
        tell_object(this_player(),
"������֪��ͷ������Ů������ָ����� !! �����Ǳ�����ػ���������ǰ\n"
"����������һ��������������һ��׳�����۵ĺ�ΰ��������˵����������\n"
"����һҹ֮�佨�ɵģ��������ļ�˾���������ˡ���������֪ʲ��ԭ��\n"
"���ͻȻ��ʧ�ˣ������Щ�ϵļ�˾����ͽ�Ǿ������ﶨ�����������Ǿ���\n"
"����Ŀ����ߡ���\n" );
                break;

        case "richman" :
        tell_object(this_player(),
	"������֪������Ǯ������ !! �����Ǹ����ص��ˣ�˭Ҳ��֪����������\n"
    "����ǰ��ͻȻ���ֿտյĴ��������������򣬶̶̼���֮�����ʹ���\n"
	"��������Ҳ��֪����������׬Ǯ�ģ���������Ϊ���Ǹ����͵ı�������\n"
	"�Ҿ�����ѧ�ʶ��ã����鲻�٣����ҳ�����һЩ�������˵ļ��⣬���\n"
	"���Ǹ����ˡ���\n" );
                break;
        case "blacksmith" :
        tell_object(this_player(),
        "������֪�����������Ľ�¯�ǻ�������� !! ��ʵ�����Ҳ���ֻܹ���\n"
	"����ش��������ˣ������������Ի�Ϊʳ����Ȼ����˵��������\n"
	"�μ����Ի�Ϊ������˷��վ��ᣬ�治��ɱ¾�ܹ�����ģ���˵�����\n"
	"�����Կ��ƻ����������������鲢�����ᵥ�����μҵ�ǰ����Ҳ������\n"
	"�������ţ���������������һ�������������ʶμҵ��ˡ�\n" );
                break;
        default :
        write(
        "������֪Ц������ �͹� ... ����С������Ϊ����Ҫ����ȥ��·��˵�����Ϳ���֪��\n"
	"�α�Ҫ�����ң�����Ǯ����Ҫ����� !!\n" );
                break;
}
        payed = 0;
        return 1;
}

int my_tactic()
{
        object victim;
        if( random(20)>6 || !(victim= query_attacker()) ) return 0;
        if( this_object()->query_temp("cast_busy") )
                return 0;
        if( (int)this_player()->query("spell_points") < 100 )
                set( "spell_points",500);
        command("cast ether-bolt at "+(string)victim->query("name"));
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
                        "������֪˵��: �͹� ! �Բ����Ϻ�ֻ�ս�ҡ�\n" ,
                        this_object() );
                return 1;
	}
	if ( num < 10 ) {
	tell_room( environment(), 
                 "������֪˵��: �͹� ! ����֪���������ѵ�ֵֻ��ЩǮ��\n" ,
                        this_object() );
		return 1;
	}
        tell_room( environment(), 
                 "������֪���ͷ��: �͹� ! ����Ҫ��Щʲ�᣿���ƻ������ꣿ\n" ,
                        this_object() );
	payed=1;

	return 1;
}
