//#pragma save_binary
 
#include <mudlib.h>
 
#define BOARD "/d/adventurer/hall/adv_board"
 
inherit GUILD;
inherit DOORS;
 
void create()
{
	object guild_master;
	::create();
	
	set("light", 1);
	set_short( "ð���߹���" );
	set_long( @C_LONG
������λ�Զ�����ð���߹��ᣬ������ʱ��ӭƣ�����Ҫ��Ϣ��ð����
���١������ӵ�һ������¥��ͨ����¥�Ĳֿ⣬�ڳ��ڸ�������Կ���һ�Ÿ�
ʾ(sign)�����ߵ�ǽ����һ��������ù�â���������Լ���һ���ܴ�Ľ���ͨ
�������һ������.
C_LONG
	);

	set("item_desc", ([
	"sign" : @C_SIGN
���Ÿ�ʾд��:
��������������������������������������������������������������������
��ӭ����ð���߹���:
    ð���߹�����������������������ð�յ��ˣ��������Ƿ������������
���ᣬ����Ĵ�����ԶΪ��������������������ѵ��(train) ���ܻ����� (
advance)�ȼ������ԣ����� help guild ���Եõ�����ϸ��˵����
    �йر��������ϸ���Σ����� help adventurers��
��������������������������������������������������������������������
C_SIGN
	]) );
	set("exits", ([
		"east" : "/d/noden/farwind/smain",
		"west" : "/d/wiz/wiz_hall",
		"up"   : "/d/noden/farwind/storage",
		"down" : "/d/noden/farwind/quest_room",
	]) );
	
	set( "pre_exit_func", ([
		"west" : "to_wiz_hall"
	]) );
	
 	/* Load up the bulletin board. */
    BOARD->frog();
    
	create_door("east", "west", ([
		"keyword"       : ({ "oak door", "door" }),
		"name"          : "oak door",
		"c_name"        : "��ľ��",
		"c_desc"        : "һ�Ƚ�ʵ���ص���ľ��",
		"status"        : "open",
	]) );
	
	guild_master=new("/d/adventurer/hall/monsters/yamor");
	guild_master->move(this_object());
 	set("objects", ([
 		"map"  : "/d/noden/farwind/items/noden_map",
		"list" : "/d/noden/farwind/items/topplr_list",
	]) );
	set( "no_monster", 1 );
	set_guild( "adventurer" ); 
	reset();
}
 
int to_wiz_hall()
{
        if( !wizardp(this_player()) ) {
                write("�Բ���ֻ����ʦ���ܽ�ȥ��\n");
                return 1;
        }
                write("�㴩����������������ʦ������\n");
        return 0;
}
 
void reset()
{
        int i;
        object *player;
 
        ::reset();
        player = users();
        for( i=0; i<sizeof(player); i++ )
                "/adm/daemons/topplayer"->log_player(player[i]);
}

int clean_up()
{
		return 0;
}
