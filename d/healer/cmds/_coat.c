//	_coat.c		�㶾��
//
//		Lilia@Eastern.Stories

// ���輼�ܣ�����ѧ 50
// �˺���Ϊ��ҩ�����˺��� * skill%
// ������Ϊ��ҩ�������Ѷ� + ��Ӫֵ/10000
	////#pragma save_binary
#include <mudlib.h>

inherit DAEMON;

int cmd_coat(string arg)
{
    object p, weapon, poison;
    int ali, i, skill;
    string wname, pname;

    p = this_player();

    if (!arg || arg == "")
	return notify_fail("������ʲ��?\n");

    sscanf (arg, "%s with %s", wname, pname);
    if (!wname || wname == "" || !pname || pname == "")
	return notify_fail("������ʲ��?\n");

    if (weapon = present(wname, p))
	if (weapon->query("weapon_class"))
	    ;
	else
	    return notify_fail("�ⲻ��������\n");

    if (poison = present(pname, p))
        if (poison->query("poison_type"))
            ;
        else
            return notify_fail("�ⲻ�Ƕ�ҩ��\n");

    if (weapon && poison)
    { 
    	skill = p->query_skill("venomlogy");
    	if (skill < 50)
	    return notify_fail("Զ������Ů����Ц��: �����ˣ���ɵ�ˣ�����ʮ��������!\n");

	ali = this_player()->query("alignment");
        if (ali >= 0)
            return notify_fail("������һ�����˽�ս���²�������� ...\n");

    	if (p->query("stop_attack") != 0)
	    return notify_fail("���ϸ�������û����ɣ������������㶾��\n");

    	if (weapon->query("poisoned/type"))
	    return notify_fail("��������Ѿ��Ϲ����ˣ�û�а취�ظ��㶾��\n");

        write("����"+weapon->query("c_name")+"Ϳ��"+poison->query("c_name")+"��\n");

    	weapon->set("poisoned/type", poison->query("poison_type"));
    	weapon->set("poisoned/time", poison->query("poison_time"));
    	weapon->set("poisoned/duration", poison->query("poison_duration"));
    	weapon->set("poisoned/harm", poison->query("poison_harm") * skill / 100);
    	i = 100 - poison->query("poison_diff") - ali/10000;
    	i = (i > 100) ? 100 : i;
    	weapon->set("poisoned/hit_rate", i);
        poison->remove();
    	return 1;
    }
    else
	return notify_fail("��û������������\n");
}

int help()
{
    write(
    @C_HELP
ָ���ʽ�� coat <����> with <��ҩ>

���ָ�����������ĳ������Ϳ�϶�ҩ��ʹ������������ǿ�����ָ��
�������ܹ����ö���ѧѵ����а��ҽʦ����ʹ�á�
C_HELP
    );
    return 1;
}

