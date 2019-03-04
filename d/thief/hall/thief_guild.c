//#pragma save_binary
#include <mudlib.h>
#define BOARD "/d/thief/hall/thief_board"
#include <stats.h>

inherit GUILD;
 
void create()
{
	object guild_master;
	::create();
	
	set("light", 1);
	set_short( "С͵����" );
	set_long( @LONG
������λ�ŵ�ٴ�½���еķ����ߵ���ů�ļ� -- С͵���ᣬ�����Ĵ���
ֻ����һ����������Ļ�������������Ե���Щ�Ұ����ڴ�����ÿ��ǽ�Ǳߣ�
���Ի����Ĳ�֪���ۼ��Ķ����ˣ�ϸϸ��̸����ʱʱ���ţ�����ȴû���˸Ҵ�
��˵�����ڶ��ߵ�ǽ�Ϲ���һ���ʾ��(plaque)���ڰ����Ļ���£�������д
Щʲ�᣿��ʾ���Ա���һ������(rope)��
LONG
	);

	set("exits", ([
		"north" : "/d/thief/hall/thief_shop",
		"east"  : "/d/noden/bluesand/temple",
		"south" : "/d/thief/hall/plan_room1",
		"west" : "/d/thief/hall/thief_trainroom",
	]) );
	
	set("pre_exit_func",([
		"north" : "check_thief" ,
		"west" : "check_thief" ,
	]));
	BOARD->frog();

        set("c_item_desc", ([
                "plaque"        : @LONG
���߹�ȥ��ϸ�Ŀ�����ʾ����д��:
������������������������������������������������������������
    ��ӭ����С͵���ᣬ�¸ҵ��������� !! ��������ŵ�ٴ�½һ��
����ָ���ߣ�����ϣ���������١��Ե���������թ�۵ȵ���������
���������������������㽫ѧ��һ�����ļ��������У�������׷��
�Ƹ����������ٵĵ�·��������� help guild ����ñ��������
һ������Ѷ��
    ���뱾����ǰ��������� help thieves ���˽Ȿ�������ɫ��
������������������������������������������������������������
LONG
	,
	"rope" : "�����ϰ���һ��ֽ��������д������(pull)�� !!��\n"]));
	guild_master=new("/d/thief/hall/monsters/pickering");
	guild_master->move(this_object());
	set( "no_monster", 1 );
	set_guild( "thief" ); 
	reset();
}
 
int clean_up()
{
		return 0;
}
void init()
{
	::init();
	add_action("do_pull","pull");
}
int do_pull(string arg)
{
	if ( arg != "rope")
		return notify_fail("��Ҫ��ʲ�᣿\n");
	if ( !"/d/noden/bluesand/temple"->query("exits/west") )
		return notify_fail("���ڵİ�����͹����ˣ�����С��һ���Ǻõ� !!\n");
	write("���������ӣ��ѳ��ڵİ��Ź�������\n");
	"/d/noden/bluesand/temple"->delete("exits/west");
	return 1;
}
int check_thief()
{
	if ( wizardp(this_player()) ) return 0;
	if ( (string) this_player()->query("class") != "thief" ) {
		write("�㲻��С͵, ���ܽ�ȥ��\n");
		return 1;
	}
	return 0;
}	

void reset()
{
        int i,j;
        object *player;

        ::reset();
        player = users();
        j=sizeof(player);
        for( i=0; i<j; i++ )
                "/d/thief/data/topthieves"->log_player(player[i]);
}

