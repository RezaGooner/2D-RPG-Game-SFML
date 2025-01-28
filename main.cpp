#include <SFML/Graphics.hpp>
#include "include/config.h"
#include <SFML/Audio.hpp>
#include <iostream>



int main() {
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), window_title);
    window.setFramerateLimit(frame_limit);

    sf::Font font;
    if (!font.loadFromFile(font_path)) {
        return -1;
    }

    sf::Texture background_texture;
    if (!background_texture.loadFromFile(beach_background_path)) {
        return -1;
    }
    background_texture.setRepeated(true);

    sf::RectangleShape background(sf::Vector2f(map_width, map_height));
    background.setTexture(&background_texture);
    background.setTextureRect(sf::IntRect(
            0,
            0,
            static_cast<int>(map_width),
            static_cast<int>(map_height))
            );

    sf::Texture right_character_texture;
    if (!right_character_texture.loadFromFile(right_character_path))
        return -1;

    sf::Texture right_run_character_texture;
    if (!right_run_character_texture.loadFromFile(right_run_character_path))
        return -1;

    sf::Texture left_character_texture;
    if (!left_character_texture.loadFromFile(left_character_path))
        return -1;

    sf::Texture left_run_character_texture;
    if (!left_run_character_texture.loadFromFile(left_run_character_path))
        return -1;

    sf::Texture arrow_texture;
    if (!arrow_texture.loadFromFile(arrow_path))
        return -1;

    sf::Texture left_arrow_texture;
    if (!left_arrow_texture.loadFromFile(left_arrow_path))
        return -1;

    sf::Texture right_arrow_texture;
    if (!right_arrow_texture.loadFromFile(right_arrow_path))
        return -1;

    std::vector<Bullet> bullets;

    sf::Texture bow_texture;
    if (!bow_texture.loadFromFile(bow_path))
        return -1;

    std::vector<sf::RectangleShape> bows;
    for (const auto& position : bow_positions) {
        sf::RectangleShape bow(sf::Vector2f(bow_texture.getSize().x, bow_texture.getSize().y));
        bow.setTexture(&bow_texture);
        bow.setPosition(position);
        bows.push_back(bow);
    }

    sf::Texture coin_texture;
    if (!coin_texture.loadFromFile(coin_path))
        return -1;

    std::vector<sf::Sprite> coins;
    for (const auto& position : coin_positions) {
        sf::Sprite coin;
        coin.setTexture(coin_texture);
        coin.setTextureRect(sf::IntRect(
                0,
                0,
                coin_frame_width,
                coin_frame_height)
                );
        coin.setPosition(position);
        coins.push_back(coin);
    }

    sf::Texture apple_texture ;
    if(!apple_texture.loadFromFile(apple_path))
        return -1 ;
    std::vector<sf::RectangleShape> apples;
    for (const auto& position : apple_positions) {
        sf::RectangleShape apple(sf::Vector2f(apple_texture.getSize().x, apple_texture.getSize().y));
        apple.setTexture(&apple_texture);
        apple.setPosition(position);
        apples.push_back(apple);
    }

    sf::Texture banana_texture ;
    if(!banana_texture.loadFromFile(banana_path))
        return -1 ;

    std::vector<sf::RectangleShape> bananas;
    for (const auto& position : banana_positions) {
        sf::RectangleShape banana(sf::Vector2f(banana_texture.getSize().x, banana_texture.getSize().y));
        banana.setTexture(&banana_texture);
        banana.setPosition(position);
        bananas.push_back(banana);
    }

    sf::Texture tree_texture ;
    if(!tree_texture.loadFromFile(tree_path))
        return -1 ;

    std::vector<sf::RectangleShape> trees;
    for (const auto& position : tree_positions) {
        sf::RectangleShape tree(sf::Vector2f(tree_texture.getSize().x, tree_texture.getSize().y));
        tree.setTexture(&tree_texture);
        tree.setPosition(position,ground_level - wall_block_height);
        trees.push_back(tree);
    }

    sf::Texture skeleton_texture ;
    if (!skeleton_texture.loadFromFile(skeleton_path))
        return -1 ;


    std::vector<Enemy> enemies;

    for (const auto& position : enemy_positions) {
        Enemy enemy;
        enemy.sprite.setTexture(skeleton_texture);
        enemy.sprite.setTextureRect(sf::IntRect(
                0,
                0,
                enemy_width,
                enemy_height)
                );
        enemy.sprite.setPosition(position);
        enemy.speed = skeleton_speed ;
        enemy.active = false;
        enemy.direction = -1;
        enemy.animation_timer = 0.0f;
        enemy.animation_frame = 0;
        enemy.health = skeleton_health ;

        enemy.health_bar_background.setSize(sf::Vector2f(enemy_width, 5));
        enemy.health_bar_background.setFillColor(gray_color);
        enemy.health_bar_background.setPosition(enemy.sprite.getPosition().x, enemy.sprite.getPosition().y - 10);
        enemy.health_bar_background.setOutlineColor(black_color);
        enemy.health_bar_background.setOutlineThickness(health_bar_outline_thickness);

        enemy.health_bar.setSize(sf::Vector2f(enemy_width, 5));
        enemy.health_bar.setFillColor(sf::Color::Green);
        enemy.health_bar.setPosition(enemy.sprite.getPosition().x, enemy.sprite.getPosition().y - 10);

        enemies.push_back(enemy);
    }

    sf::Sprite character(right_character_texture);
    character.setPosition(character_first_position_x, character_first_position_y - wall_block_height);

    sf::View camera(sf::FloatRect(0, 0, view_width, view_height));

    sf::Clock clock;
    sf::Clock animation_clock;

    sf::Texture ground_block_texture;
    if (!ground_block_texture.loadFromFile(wall_block_path))
        return -1;

    sf::RectangleShape ground_block(sf::Vector2f(wall_block_width, wall_block_height));
    ground_block.setTexture(&ground_block_texture);

    std::vector<sf::RectangleShape> ground_blocks;
    for (int x = 0; x < map_width; x += wall_block_width) {
        ground_block.setPosition(x, ground_level);
        ground_blocks.push_back(ground_block);
    }

    std::vector<sf::RectangleShape> jump_blocks;
    sf::Texture platform_texture;
    if (!platform_texture.loadFromFile(platform_path))
        return -1;

    for (const auto& position : jump_block_positions) {
        sf::RectangleShape jumpBlock(sf::Vector2f(platform_texture.getSize().x, platform_texture.getSize().y));
        jumpBlock.setTexture(&platform_texture);
        jumpBlock.setPosition(position);
        jump_blocks.push_back(jumpBlock);
    }

    sf::RectangleShape health_bar_background(sf::Vector2f(health_bar_background_x, health_bar_background_y));
    health_bar_background.setFillColor(gray_color);

    sf::RectangleShape health_bar(sf::Vector2f(health_bar_background_x, health_bar_background_y));

    sf::Text text;
    text.setFont(font);
    text.setString(score_board_text);
    text.setCharacterSize(score_board_text_size);
    text.setFillColor(score_board_text_color);
    text.setOutlineColor(score_board_text_outline_color);
    text.setOutlineThickness(score_board_text_outline_thickness);


    sf::SoundBuffer arrow_shoot_sound_buffer ;
    if (!arrow_shoot_sound_buffer.loadFromFile(arrow_shoot_sound_path))
        return -1 ;
    sf::Sound arrow_shoot_sound(arrow_shoot_sound_buffer);

    sf::SoundBuffer coin_sound_buffer ;
    if (!coin_sound_buffer.loadFromFile(coin_sound_path))
        return -1 ;
    sf::Sound coin_sound(coin_sound_buffer);

    sf::SoundBuffer jump_sound_buffer ;
    if (!jump_sound_buffer.loadFromFile(jump_sound_path))
        return -1 ;
    sf::Sound jump_sound(jump_sound_buffer);

    sf::SoundBuffer damage_sound_buffer ;
    if (!damage_sound_buffer.loadFromFile(damage_sound_path))
        return -1 ;
    sf::Sound damage_sound(damage_sound_buffer);

    sf::SoundBuffer item_pickup_sound_buffer ;
    if (!item_pickup_sound_buffer.loadFromFile(item_pickup_sound_path))
        return -1 ;
    sf::Sound item_pickup_sound(item_pickup_sound_buffer);

    sf::SoundBuffer apple_bite_sound_buffer ;
    if (!apple_bite_sound_buffer.loadFromFile(apple_bite_sound_path))
        return -1 ;
    sf::Sound apple_bite_sound(apple_bite_sound_buffer);

    sf::Music main_music ;
    if (!main_music.openFromFile(main_music_path))
        return -1 ;
    main_music.play();
    main_music.setLoop(true);
    main_music.setVolume(10);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space && is_on_ground && is_jump_released) {
                    velocity_y = jump_force;
                    is_jumping = true;
                    is_on_ground = false;
                    is_jump_released = false ;
                    jump_sound.play();
                } if (event.key.code == sf::Keyboard::LControl && is_gun && arrow_num > 0) {
                    Bullet bullet;
                    bullet.speed = bullet_speed;
                    bullet.direction = (is_right) ? 1 : -1;

                    sf::Sprite bulletSprite;
                    if (bullet.direction > 0)
                        bulletSprite.setTexture(right_arrow_texture);
                    else
                        bulletSprite.setTexture(left_arrow_texture);

                    bulletSprite.setPosition(
                            character.getPosition().x + (bullet.direction * character.getGlobalBounds().width / 2),
                            character.getPosition().y - character.getGlobalBounds().height / 5
                    );

                    bullet.shape = bulletSprite;

                    bullets.push_back(bullet);

                    arrow_num--;
                    arrow_shoot_sound.play();
                }
            } else if (event.type == sf::Event::KeyReleased){
                if (event.key.code == sf::Keyboard::Space)
                    is_jump_released = true ;
            }
        }

        float deltaTime = clock.restart().asSeconds();

        int i = 0 ;
        for (auto& coin : coins) {
            if (animation_clock.getElapsedTime().asSeconds() > animation_duration) {
                coin_animation_frame = (coin_animation_frame + 1) % coin_animation_frame_num;
                coin.setTextureRect(sf::IntRect(
                        coin_animation_frame * coin_frame_width,
                        0,
                        coin_frame_width,
                        coin_frame_height
                ));
                //animation_clock.restart();
            } if (coin.getGlobalBounds().intersects(character.getGlobalBounds())) {
                coins.erase(coins.begin() + i);
                score += coin_score ;
                coin_sound.play();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            is_right = true ;
            character.move(character_speed * deltaTime, 0);
            if (animation_clock.getElapsedTime().asSeconds() > animation_duration) {
                character_animation_frame = (character_animation_frame + 1) % character_animation_frame_num;
                character.setTexture(right_run_character_texture);
                character.setTextureRect(sf::IntRect(
                        character_animation_frame * character_sprite_size.x,
                        0,
                        character_sprite_size.x,
                        character_sprite_size.y
                ));
                animation_clock.restart();
            }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            is_right = false ;
            character.move(-character_speed * deltaTime, 0);
            if (animation_clock.getElapsedTime().asSeconds() > animation_duration) {
                character_animation_frame = (character_animation_frame + 1) % character_animation_frame_num;
                character.setTexture(left_run_character_texture);
                character.setTextureRect(sf::IntRect(
                        character_animation_frame * character_sprite_size.x,
                        0,
                        character_sprite_size.x,
                        character_sprite_size.y
                ));
                animation_clock.restart();
            }
        } else {
            character_animation_frame = 0;
            if (character.getTexture() == &right_run_character_texture) {
                character.setTexture(right_character_texture);
                character.setTextureRect(sf::IntRect(
                        0,
                        0,
                        character_sprite_size.x,
                        character_sprite_size.y
                ));
            } else if (character.getTexture() == &left_run_character_texture) {
                character.setTexture(left_character_texture);
                character.setTextureRect(sf::IntRect(
                        0,
                        0,
                        character_sprite_size.x,
                        character_sprite_size.y
                ));
            }
        }

        if (!is_on_ground) {
            velocity_y += gravity;
            character.move(0, velocity_y);
        }

        sf::Vector2f characterPosition = character.getPosition();
        if (characterPosition.x < 0) {
            character.setPosition(0, characterPosition.y);
        } else if (characterPosition.x + character.getGlobalBounds().width > map_width) {
            character.setPosition(map_width - character.getGlobalBounds().width, characterPosition.y);
        }



        for (size_t i = 0; i < bullets.size(); ++i) {
            bullets[i].shape.move(bullets[i].speed * bullets[i].direction * deltaTime, 0);

            for (size_t j = 0; j < enemies.size(); ++j) {
                if (bullets[i].shape.getGlobalBounds().intersects(enemies[j].sprite.getGlobalBounds())) {
                    enemies[j].health -= bullet_damage;
                    bullets.erase(bullets.begin() + i);
                    --i;
                    if (enemies[j].health <= 0) {
                        enemies.erase(enemies.begin() + j);
                        score += 50 ;
                    }
                    break;
                }
            }

            if (bullets[i].shape.getPosition().x < 0 ||
                    bullets[i].shape.getPosition().x > (view_width / 2) + camera.getCenter().x) {
                bullets.erase(bullets.begin() + i);
                --i;
            }
        }

        int j = 0 ;
        for (auto& enemy : enemies) {
            enemy.health_bar.setPosition(enemy.sprite.getPosition().x, enemy.sprite.getPosition().y - 10);
            enemy.health_bar_background.setPosition(enemy.sprite.getPosition().x, enemy.sprite.getPosition().y - 10);

            float healthPercentage = static_cast<float>(enemy.health) / skeleton_health;
            enemy.health_bar.setSize(sf::Vector2f(enemy_width * healthPercentage, 5));

            if (healthPercentage > 0.5f) {
                enemy.health_bar.setFillColor(green_color);
            } else if (healthPercentage > 0.25f) {
                enemy.health_bar.setFillColor(yellow_color);
            } else {
                enemy.health_bar.setFillColor(red_color);
            }

            window.draw(enemy.sprite);
            window.draw(enemy.health_bar_background);
            window.draw(enemy.health_bar);
        }
        for (auto& enemy : enemies) {

            if (enemy.sprite.getPosition().x > camera.getCenter().x - view_width / 2 &&
                enemy.sprite.getPosition().x < camera.getCenter().x + view_width / 2) {
                enemy.active = true;
            } else {
                enemy.active = false;
            }

            if (enemy.active) {
                if (enemy.sprite.getGlobalBounds().intersects(character.getGlobalBounds())) {
                    current_health -= skeleton_damage;
                    enemies.erase(enemies.begin() + j);
                    is_gun = false ;
                    arrow_num = 0 ;
                    damage_sound.play();
                }

                enemy.sprite.move(enemy.direction * enemy.speed * deltaTime, 0);

                if (enemy.sprite.getPosition().x < 0 ||
                    enemy.sprite.getPosition().x + enemy_width > map_width) {
                    enemy.direction *= -1;
                }

                for (const auto& tree : trees) {
                    if (enemy.sprite.getGlobalBounds().intersects(tree.getGlobalBounds())) {
                        enemy.direction *= -1;
                        break;
                    }
                }

                enemy.animation_timer += deltaTime;
                if (enemy.animation_timer >= animation_duration) {
                    enemy.animation_frame = (enemy.animation_frame + 1) % skeleton_frame_num;
                    enemy.sprite.setTextureRect(sf::IntRect(
                            enemy.animation_frame * enemy_width,
                            0,
                            enemy_width,
                            enemy_height
                            ));
                    enemy.animation_timer = 0.0f;
                }
            }
            j++ ;
        }


        for (auto& block : ground_blocks) {
            if (character.getGlobalBounds().intersects(block.getGlobalBounds())) {
                if (velocity_y > 0) {
                    character.setPosition(
                            character.getPosition().x,
                            block.getPosition().y - character.getGlobalBounds().height
                            );
                    velocity_y = 0;
                    is_jumping = false;
                    is_on_ground = true;
                }
            }
        }
        int k = 0 ;
        for (auto& apple : apples) {
            if (character.getGlobalBounds().intersects(apple.getGlobalBounds())) {
                if (current_health + apple_health > max_health)
                    current_health = max_health ;
                else
                    current_health += apple_health ;
                apples.erase(apples.begin() + k);
                apple_bite_sound.play();
            }
            k++;
        }

        j = 0 ;
        for (auto& bow : bows) {
            if (character.getGlobalBounds().intersects(bow.getGlobalBounds())) {
                is_gun = true ;
                arrow_num += arrow_charge ;
                bows.erase(bows.begin() + j);
                item_pickup_sound.play();
            }
            j++;
        }

        i = 0 ;
        for (auto& banana : bananas) {
            if (character.getGlobalBounds().intersects(banana.getGlobalBounds())) {
                if (current_health + banana_health > max_health)
                    current_health = max_health ;
                else
                    current_health += banana_health ;
                bananas.erase(bananas.begin() + i);
                apple_bite_sound.play();
            }
            i++;
        }

        for (auto& block : jump_blocks) {
            if (character.getGlobalBounds().intersects(block.getGlobalBounds())) {
                if (velocity_y > 0) {
                    character.setPosition(
                            character.getPosition().x,
                            block.getPosition().y - character.getGlobalBounds().height
                            );
                    velocity_y = 0;
                    is_jumping = false;
                    is_on_ground = true;
                } else  {
                    character.setPosition(
                            character.getPosition().x,
                            block.getPosition().y + block.getSize().y
                            );
                    velocity_y = 0;
                }
            } else {
                velocity_y += gravity;
                character.move(0, velocity_y);
            }
        }

        health_bar_background.setPosition(character.getPosition().x, character.getPosition().y - 10);
        health_bar_background.setOutlineColor(sf::Color::Black);
        health_bar_background.setOutlineThickness(1);
        health_bar.setPosition(health_bar_background.getPosition());
        float healthPercentage = current_health / max_health;
        health_bar.setSize(sf::Vector2f(health_bar_background_x * healthPercentage, health_bar_background_y));

        if (healthPercentage > 0.8f) {
            health_bar.setFillColor(sf::Color::Green);
        } else if (healthPercentage > 0.6f) {
            health_bar.setFillColor(sf::Color(173, 255, 47));
        } else if (healthPercentage > 0.4f) {
            health_bar.setFillColor(sf::Color::Yellow);
        } else if (healthPercentage > 0.2f) {
            health_bar.setFillColor(sf::Color::Red);
        } else {
            health_bar.setFillColor(sf::Color(139, 0, 0));
        }

        sf::Vector2f cameraCenter = character.getPosition();
        cameraCenter.y = view_height / 2;
        camera.setCenter(cameraCenter);

        if (camera.getCenter().x - (view_width / 2) < 0)
            camera.setCenter(view_width / 2, camera.getCenter().y);
        if (camera.getCenter().x + (view_width / 2) > map_width)
            camera.setCenter(map_width - (view_width / 2), camera.getCenter().y);

        window.setView(camera);

        text.setString("Hi Player!\nScore >> " + std::to_string(score) + "\nArrow >> " + std::to_string(arrow_num));
        text.setPosition(camera.getCenter().x - view_width / 2 + 10, camera.getCenter().y - view_height / 2 + 10);

        window.clear();
        window.draw(background);
        for (auto& block : ground_blocks)
            window.draw(block);

        for (auto& coin : coins)
            window.draw(coin);

        for (auto& bow : bows)
            window.draw(bow);

        for (auto& apple : apples)
            window.draw(apple);

        for (auto& banana : bananas)
            window.draw(banana);

        for (auto& tree : trees)
            window.draw(tree);

        for (const auto& block : jump_blocks)
            window.draw(block);

        window.draw(text);
        window.draw(character);
        window.draw(health_bar_background);
        window.draw(health_bar);

        for (auto& enemy : enemies) {
            window.draw(enemy.sprite);
            window.draw(enemy.health_bar_background);
            window.draw(enemy.health_bar);
        }
        for (const auto& bullet : bullets)
            window.draw(bullet.shape);

        window.display();
    }

    return 0;
}
