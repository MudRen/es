// book.c		�嶾�ش�
//
//	��ҩ������
//
//			Lilia

#include <mudlib.h>
#include <conditions.h>

#define LIST_PATH "/d/healer/poison/"

inherit OBJECT;

void init()
{
    add_action("read_book", "read");
}

void create()
{
    seteuid(getuid());
    add("id", ({"drug", "book"}));
    set_name("drug book", "�嶾�ش�");
    set_short("drug book", "�嶾�ش�");
    set_long("����һ���������õ��飬��������������ģ��������֣����嶾�ش���\n");
    set("unit", "��");
    set("no_sale", 1);
    set("bulk", 1);
    set("mass", 1);
}

string query_index()
{
    string index;

    index = "���ߣ�����֮ҩҲ����ʹ��֮�ˣ�������ҩ��ʶ���ݣ���������\n"
	    "�����ƶ�������춶������Դ���֮�䣬������֮�̻壬����������\n"
	    "��֮һ����Ϊ�������񼼣�����ʧ�������Ա�֮��飬�Դ���Ե��\n"
	    "�����ط����ǲ����Ѷ���֮������Ե���мǡ�\n\n"
	    "				    		 ��Ů\n";

    return index;
}

int read_book(string str)
{
    object owner;
    int page;
    owner = this_player();

    // û�����׾������嶾�ش��Ļ� .... �ٺ� ....
    // ��ħû����

    if ( !(owner->query("armor/hands")) && owner->query("race") != "beholder" ) 
    {
	tell_object(owner, "����ֽӴ���ҳ֮�ᣬͻȻ�е�һ��������\n");
        (CONDITION_PREFIX + "simple_poison")->apply_effect(owner, 8, 8);
        return 1;
    }

    if (str == "book" || str == "drug" || str == "�嶾�ش�")
    {
	write("��С�ĵؽҿ��˷��棬ר�ĵض������� ...\n\n");
        write(query_index());
	write("\n���˰���ʵ�ڿ��������ڽ�ʲ�ᣬ�㲻����Ͽ�����ҩ��(list)д������ ...\n");
	return 1;
    } else if (str == "list") {
        cat(LIST_PATH"list");
        return 1;
    } else if (sscanf(str, "page %d", page) == 1) {
	if (file_exists(LIST_PATH"page" + page))
	{
	    cat(LIST_PATH"page" + page);
	    return 1;
   	} else {
            write("�㷭����ȥ�������Ҳ�����ҳ���ƺ��Ǳ���˺ȥ�� ....\n");
            return 1;
	}
    } else {	
	return notify_fail("��ʲ�᣿\n");
    }
}


