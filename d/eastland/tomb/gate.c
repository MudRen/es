#include <almuhara.h>
#define MAX_DRAGON 4
inherit DOORS;
inherit ROOM;
void create()
{
	::create();
	set_short("����ʯ��");
	set_long( @LONG_DESCRIPTION
����������һ��������ʯ�ң�����ƺ��ǵص����յ㡣ǽ����ɢ��һ������Ĺ�â��
ӳ�����ڵľ�������Եø�����졣������ǰ��һ�Ⱦ޴��ʯ�ţ�ʯ������ֻ������
���ľ����ݷ�Ҫ�Ʊڶ�������������Ŀ���㲻�����������̾��˫�������ƺ���һ��С
��(hole)�����鲻�Խ���������ǰ���������
LONG_DESCRIPTION
	);
        set( "light",1 );
        set( "mob_num",0 );
	set( "exits", ([ 
		"north" : TOMB"/inner1",
		"up" : TOMB"/down3"
		]));
	create_door( "north","south",
		   (["keyword" : ({"door", "stone"}),
			"name"    : "stone door",
			"c_name"  : "��ʯ��",
			"c_desc"  : "һ�ȳ����ʯ�ţ����᲻֪����ʲ������...",
			"lock"    : "TOMBKEY_1",
			"status"  : "locked",
		     ]) );
	add( "c_item_desc", ([
	      	"hole" :@C_ITEM_DESC_1
����С�����������˶���Χ�Ļҳ��������ᣬ�������Ǹ���Բ��С���ۣ�����
���Է�(put)ʲ��ԲԲ��С�������� !! �����Ϸ�������һ����(writings)��
C_ITEM_DESC_1
,		"writings" :@C_ITEM_DESC_2
�� �Ȼ����� �� �������� ������ �ۣ��ѵ�������Ǵ�˵�ж����ʵ۵���Ĺ ����
C_ITEM_DESC_2
	   ]));
	   set( "pre_exit_func", ([
	   	"north" : "loop_exit" ]) );
           reset();
}

void init()
{
	add_action( "do_place", "put" );
}

int do_place (string str)
{
	object player,ob;
	string orb;
	int i;
    
    	player = this_player();
    
	if ( !str || str!="orb into hole")
		return 0;

	ob = present( "golden dragon orb" , player);
	if(!ob) {
		tell_object(player,"������û���ʺϵĶ�����\n");
		return 1;
	}

 	tell_object( player, 
		    "\n��ѽ�����Ž�С���\n"
		    "\nͻȻ����һ�����죬��ʯ�Ż����ش���\n");
	tell_room( environment(player), 
		player->query("c_cap_name") + "��һ��С�����Ž����\n" 
		"\nͻȻ����һ�����죬��ʯ�Ż����ش���\n",
		player );
        set_status("north","open");
        update_link("north");		
 	player->set_temp("DRAGON_ORB",1);			
       	ob->remove();
       	return 1;
}

int loop_exit()
{
	object player;
	
	player = this_player();
	if ( !present("golden dragon",this_object())) {	
        if ( query("mob_num") < MAX_DRAGON ) {
		
                if ( !player->query_temp("DRAGON_ORB") ) {
                tell_room( this_object(),
                "\nʯ������ֻ����ͻȻ�۾�һ����������צ��������˹�������\n"
                         );
                new(MOB"/dragon")->move(this_object());
                new(MOB"/dragon")->move(this_object());
		this_object()->add("mob_num",2);
                return 1;
		}
                else    return 0;
	}
	}
	if ( !player->query("player_invisible") && present( "dragon", this_object() ) ) {
		write("���������ڱ�����ʹ���޷����롣\n" );
		tell_room( this_object(), 
			sprintf("%s�������ߣ�ȴ��������ס��\n", player->query("c_cap_name"))
		, player);
		return 1;
	}
	return 0;	 	
}	
