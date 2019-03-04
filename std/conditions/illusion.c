//#pragma save_binary

// This is a condition object
// A player may have more than one conditions (usually bad condition) that
// take effects with a certain frequency. Thus condition WILL BE SAVED in
// save files and can only be solved by calling the function "remove_effect"
// defined in this object. The function "effect" is called in a certain
// frequency from the heart_beat ( heal_up() in /std/body/attack.c )

// Created by Lilia@Eastern.Stories (11-19-95)

#define EFFECT_NAME "illusion"

void effect(object player);
void remove_effect(object player);
void apply_effect(object player, int duration, int damage);

// This is the effect of illusion. Its data packet is simple:
// ({ <frequency>, <duration>, <damage> })
// Notice we must maintain the duration everytime the effect() is called.

void effect(object player)
{
    mixed *cond_data;
    int damage;

    cond_data = player->query("conditions/" + EFFECT_NAME);
    if (!sizeof(cond_data) == 3) return;

    tell_object(player, set_color("����Ĳ�ס����...\n", "HIB", player));
    tell_object(player, set_color("���ȵĺ����罬...\n", "HIY", player));
    cond_data[1]--;
    player->set("conditions/" + EFFECT_NAME, cond_data);
    if (cond_data[1] < 1) remove_effect(player);
    player->receive_special_damage(cond_data[2]);
    tell_room(environment(player), player->query("c_name") + "��ס�ز������ƺ��������������ʹ��...\n", player);
}

void remove_effect(object player)
{
    tell_object(player, set_color("���������춴ӻþ������ѹ���...\n", "HIC", player));
    player->delete("conditions/" + EFFECT_NAME);
}

varargs void apply_effect(object player, int duration, int damage)
{
    mixed *cond_data;

    cond_data = player->query("conditions/" + EFFECT_NAME);
    if (!cond_data)
    {
      	tell_object(player, set_color("������Լ��߽���һ������ĵط��������������ĵذ�ͱ�����ǽ...\n", "HIG", player));
	player->set("conditions/" + EFFECT_NAME, ({4, duration, damage}));
    }
    else
    {
	if (duration > cond_data[1]) cond_data[1] = duration;
	if (damage > cond_data[2]) cond_data[2] = damage;
	else cond_data[2]++;
	tell_object(player, set_color("��ĸо�Խ��Խǿ�ң��ݷ������һ��...\n", "HIG", player));
	player->set("conditions/" + EFFECT_NAME, cond_data);
    }
}
