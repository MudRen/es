
#include <zeus.h>

inherit ROOM;

void create()
{
	::create();
	set_short("ˮ������");
	set_long(@CLong
����һ������ĵط�����һ����С�͵ĸۿڣ��������һ�����ͻ����
�ص㣬���쵽���������һ���յ㣮�����ƺ�������һ��Ѫ�ȵ���Ϣ��һ��
����ɱ���������˲����������Ϸ���һ���ļ���ˮ��(river) �������ͨ��
����û��ʮ�ָ߳�����Ӿ�����ǲ��еģ�
CLong
);
set("item_desc",(["river":
"����һ�����ٷǳ���ĺ������Ӷ��治֪��ʲ��ط���Ҳ��\���Թ�ȥ��������\n"
	]) ); 

set("exits",([ "north":ZROOM"/mine12"
	]));

reset();
}
void init()
{
add_action("do_pass","pass");
}
int do_pass(string str){
 	int skills;
	skills = (int)this_player()->query_skill("swimming");
	if(!str||str!="river"){
	write("����ͨ��ʲ��?\n");
	return 1;
		}
	if ( random(skills) < 40 && skills < 40){
	write("\n������ι�ȥ�����Ǻܲ��ҵı�ˮ�������ˣ�����\n");
	tell_room(environment(this_player()),(
	"�㿴��"+this_player()->query("c_name")+"��˧��������ˮ�У�����ȴ���αߺ�������\n")
	,this_player());
	this_player()->move_player(ZROOM"/port.c","SNEAK");
	return 1;
	}
	if (random(skills) < 40  && skills >40 ){
	write("\n���Ŭ������ǰ�Σ����Ǳ�ˮ��������ˣ�����\n");
	tell_room(environment(this_player()),(
	"�㿴��"+this_player()->query("c_name")+"��һ�ֿ�Ц�����ƣ����������˻�����\n")
	,this_player() 
	              );
	return 1;
	}
	write("��ƾ�����߳���Ӿ�����˷���ӿ�����εִ�˰�����\n");
	tell_room(environment(this_player()),(
	"�㿴��"+this_player()->query("c_name")+"��������ε��˶԰�����\n")
	,this_player());
	this_player()->move_player(ZROOM"/store_room.c","SNEAK");
	return 1;
}