#include "../story.h"

inherit ROOM;
int bone=1;
int i=0;
void create()
{
        ::create();
	set_short("��Ѩ");
	set_long( @LONG
����һ��͸��Щ��΢���ߵ�������Ѩ�������������ķ��ڵ�������ȦȦ�γ�
һ��СС������������ַ������������ǰ��ι�ǽ�ڷ����������ݡ�����������
���У������������ڶ����㳰Ц���ҷ��������Ц�����������ĸо�����������ë
���Ȼ�亹ֱ������Ȼ����֪�����ߵ�ʲ�ᶫ������ͷһ������Ȼ��һ�Ѱ׹�(bone
)�������ⲻ�Ǹ����Ƶĵط����㻹�ǿ��뿪����Ϊ�
LONG
	);
	set( "exits", ([ 
       	        "up" : SAREA"vhole1",
       	      "down" : SAREA"room_t",
        ]) );
	reset();
}
int clean_up() { return 0; }
void init()
{
    add_action("do_search","search");
}
void qq()
{
    bone=1;
}
void rr()
{
   i++;
   if ( i < 2 ) return ;
   i=0;
   call_out("qq",3600);
   return ;
}
int do_search(string arg)
{
    object head,tail;
    if ( !arg || arg !="bone" ) return 0;
    if ( !bone ) {
       tell_room(this_object(),"��Ѱ׹��Ѿ������ҹ��� ! \n");
       return 1;
    }
    tell_room(this_object(),"\nͻȻ�Ӱ׹Ƕ���ĳ�һֻ������ ! \n\n");
    head=new(SMOB"head");
    tail=new(SMOB"tail");
    head->set("other",tail);
    tail->set("other",head);
    head->move(this_object());
    tail->move(find_object_or_load(SAREA"room_t"));
    bone=0;
    return 1;
}