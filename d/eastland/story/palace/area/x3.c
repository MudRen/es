#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("���ڳ���");
	set_long( @LONG
���ڳ��ȵ������Ѿ��Ǿ�ͷ���ȵ������Ϸ������졣�ȵ������̵أ����˵���
��ϸ�����ÿ����Ƕ��ȭ��ҹ���飬��Ө���ԣ���ҫ������ͨ���������м���¥��
��ÿ������֪�ü��㣬ÿ��ż䣬ͨ��������ɣ�������ף����Ŵ䶫����������
������ׯ�ϣ�������ٱ��ϸ��ǰ�漸�㣬���ĳ����޲������������칤���
��ⱦ�����ֳ���ɫ���㣬����Ӻ������֮�¡�¥��֮��Χ��һС�͵��ã�������
ͥ����ⱦ����
LONG
	);
        set("light",1);
        set("exits" , ([
           "southeast" : SPALACE"s2",
           "southwest" : SPALACE"house3",           
        ]) );
        set("pre_exit_func",([
            "southwest":"can_pass"]));
        reset();
}        
int can_pass()
{
        if ( this_player()->query("palace_war") ) return 1;
        return 0;
}