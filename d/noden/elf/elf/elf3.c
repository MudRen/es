#include "../layuter.h"

inherit ROOM;

void create()
{
	::create();
	set_short("С��");
	set_long( @LONG_DESCRIPTION
����һ��ͨ����ԭ��С����·�ϱ鲼��õ�廨(rose)�ԣ�ʹ�����С��
�����ͨ�����ⱻ���ˡ�
LONG_DESCRIPTION
	);
	set_outside("hamlet");
    set("item_desc",([
        "rose" : @ROSE
   �˴���õ��һ���ļ����������������乹��һ��������ͼ����
   �������ص��Ǵ˴����еĺ�õ�壬�����ص�ɫ�ʴ����˿ֲ�����
   ����Ϣ��
ROSE
   ]));
    set("objects",([
            "butterfly" : LMONSTER"butterfly",
            "elf guard" : LMONSTER"elf_guard", ]));
	set( "light", 1 );
	set( "pre_exit_func", ([
		"south" : "check_level" ]) );
	set( "exits", ([
		"north" : LELF"elf2.c",
		"south" : LELF"elf6.c"
	]) );
	
	reset();
}

int check_level()
{
	if( wizardp(this_player()) || !present("guard") ||
		(int)this_player()->query_level() < 7 ) return 0;
	tell_object( this_player(), 
		"��������˵: Ϊ�˴��ԭ�ĺ�ƽ, ֻ׼ newbie ���롣\n"
		"����������ֹ��ǰ��!\n" 
	);
	return 1;
}
