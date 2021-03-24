/**
 * Unit tests for Species.
 *
 * Copyright (c) 2019, Sekhar Ravinutala.
 */

#include "species/species.h"

// Ignore possible red squggly below (bazel will automatically install gtest)
#include <gtest/gtest.h>

#include <type_traits>
#include <string>
#include <ctime>
#include <random>

// Namespace to prevent global name clash
namespace {
  time_t now = time(NULL);
  unsigned int seed = std::localtime(&now)->tm_sec;
  char name[10];
}

// Random data for tests
#define HEIGHT() (5.0 + (rand_r(&seed) % 16) / 10.0)
#define WEIGHT() (100 + (rand_r(&seed) % 200))
const char *crazyName() {
  snprintf(name, sizeof(name), "crazy-%2d", seed);
  return name;
}

// Test Eevak
TEST(species, eevak) {
  // Default.
  Eevak eevak;
  EXPECT_FALSE(eevak.isRunning());

  // Must not be humanoid.
  EXPECT_FALSE((std::is_base_of<Humanoid, Eevak>::value));

  // Check running.
  eevak.run();
  EXPECT_TRUE(eevak.isRunning());

  // Stop.
  eevak.stop();
  EXPECT_FALSE(eevak.isRunning());
}

// Test Gelatin
TEST(species, gelatin) {
  double weight = WEIGHT();

  // Create
  Gelatin gelatin(weight);
  EXPECT_EQ(gelatin.weight(), weight);
  EXPECT_STREQ(gelatin.shape(), "sphere");

  // Must not be humanoid
  EXPECT_FALSE((std::is_base_of<Humanoid, Gelatin>::value));

  // Morph to "flat" shape
  gelatin.morph("flat");
  EXPECT_STREQ(gelatin.shape(), "flat");

  // Go back to default
  gelatin.morph();
  EXPECT_STREQ(gelatin.shape(), "sphere");

  // Ignore all other morph attempts
  gelatin.morph(crazyName());
  EXPECT_STREQ(gelatin.shape(), "sphere");

  // Split into two
  Gelatin newGelatin = gelatin.split();
  EXPECT_NE(newGelatin, gelatin);
  EXPECT_EQ(gelatin.weight(), weight / 2);
  EXPECT_EQ(newGelatin.weight(), weight / 2);
  EXPECT_STREQ(newGelatin.shape(), gelatin.shape());
}

// Test Human
TEST(species, human) {
  double height = HEIGHT();
  double weight = WEIGHT();

  // Create
  Human human(false, height, weight);
  EXPECT_FALSE(human.isMale());
  EXPECT_EQ(human.height(), height);
  EXPECT_EQ(human.weight(), weight);

  // Must be humanoid
  EXPECT_TRUE((std::is_base_of<Humanoid, Human>::value));
}

// Test Kaylon
TEST(species, kaylon) {
  double height = HEIGHT();
  double weight = WEIGHT();

  // Create
  Kaylon kaylon(height, weight);
  EXPECT_EQ(kaylon.height(), height);
  EXPECT_EQ(kaylon.weight(), weight);
  EXPECT_FALSE(kaylon.isFiring());

  // Must be humanoid
  EXPECT_TRUE((std::is_base_of<Humanoid, Kaylon>::value));

  // Check firing
  kaylon.startFiring();
  EXPECT_TRUE(kaylon.isFiring());
  kaylon.stopFiring();
  EXPECT_FALSE(kaylon.isFiring());
}

// Test Moclan
TEST(species, moclan) {
  double height = HEIGHT();
  double weight = WEIGHT();

  // Create
  Moclan moclan(height, weight);
  EXPECT_EQ(moclan.height(), height);
  EXPECT_EQ(moclan.weight(), weight);
  EXPECT_FALSE(moclan.isEgg());

  // Must be humanoid
  EXPECT_TRUE((std::is_base_of<Humanoid, Moclan>::value));

  // Lay egg
  Moclan moclanEgg = moclan.layEgg();
  EXPECT_FALSE(moclan.isEgg());
  EXPECT_TRUE(moclanEgg.isEgg());

  // Hatch
  moclanEgg.hatch();
  EXPECT_FALSE(moclanEgg.isEgg());
}
