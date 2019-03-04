#include <../goomay.h>
inherit Mob_special;
int payed;
void init()
{
	::init();
	add_action( "tip_me", "pay");
        add_action( "ask_me", "ask");
}

void create()
{
        ::create();
        set_level( 5 );
        set_name( "the waiter", "��С��" );
        add( "id", ({ "waiter" }) );
        set_short( "��С��" );
        set_long(
@LONG
�㿴��һ��ʮ�����С���ӣ�����һ���಼Сñ��Ц����������ϳ��˼���
�ഺ����һ˫����Ĵ��۾��Ե�ʮ���鶯�����Ǳ���ĵ�С�����������İ�
������ֻҪ�����˽�������Ҫ����һ�����������Ҫ�󣬵�Ȼ����ҲҪ����
��������С�
LONG
        );
        set( "gender", "male" );
	set("race","halfling");
	payed=0;
        set_natural_armor( 25, 10 );
        set_natural_weapon( 6, 5, 11 );
        set_skill( "dodge", 80 );
        set_perm_stat("dex",10);
        set_perm_stat("str",10);
	set( "defense_type","dodge");
        set( "alignment", 150 );
        set( "wealth/silver", 20 );
        set("special_attack",(["damage_type" : "none","main_damage" : 5,
                                "random_dam" : 5 , "hit_rate" : 13]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
"��С��������Ĩ���������ϳ������ĵ�һ�����صĴ��������ϣ���е�һ���ʹ..\n\n");
set("c_room_msg","��С����Ĩ�����");
set("c_room_msg2", "���������ͷת�� ...\n");
}
void ask_scribe()
{
        tell_object(this_player(),
        "��С����������Щ���ٵ��˼��Ӵ�úܣ������Ǽ������ģ������������\n���ǵ���˾���Ǿ�������ඡ�\n" );
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
	if (mon_name!="waiter")
	{
		this_player()->command("ask "+str);
		return 0;
	}
        if (!payed) {
                write(
                "��С��Ц������ �͹� ... �ܵ���˼��˼�� !! �˽��𣿡� \n" );
                return 1;
	}

switch (subject) {
        case "hunter" :
        tell_object(this_player(),
	"��С�����������˰��������⼸��û������Ұζ�����������㷷���ξŸ������죬\n"
        "������������� ..��\n" );
                break;

        case "herb" :
        tell_object(this_player(),
	"��С��������˵�����ҩ�ݰ�����������Ǯ�����Ĺ��𣿴���������õ�\n"
	"��ҽ���������ˣ����������㲻�����������ˣ�˭֪���أ��������������\n"
	"��˭��Ȱ����Ǯ����ģ���һ����������ﲻ���ˡ���\n" );

                break;
	case "maid" :
        tell_object(this_player(),
	"��С������������˵С������Ѿͷ��Ȱ����ñ�ȥ�����������������������\n"
        "��ķǳ����ģ��� ������˵������������ռ����顣��\n" );

		break;
        case "magistrate" :
			ask_scribe();
                break;
        case "captain" :
                        ask_scribe();
                break;
        case "scribe" :
                        ask_scribe();
                break;

        default : 
	write(
	"��С��Ц������ �͹� ... ��Ȼ�Ҳ�֪������֪�����£�����Ҳ��һ�����Ⱑ�� \n" );
                break;
}
	payed = 0;
	return 1;
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
                        "С����˵��: �͹� ! �Բ��𣬽���������н��Ү��\n" ,
                        this_object() );
                return 1;
	}
	if ( num < 50 ) {
                tell_room( environment(), 
                 "С����˵��: �͹� ! С��һ�������ѵ�ֵֻ��ЩǮ��\n" ,
                        this_object() );
		return 1;
	}
	payed=1;
	tell_object(this_player(),
		    "��С������գգ��Ц���������� ... �͹� !! ����֪��Щʲ���أ���\n" );

	return 1;
}

