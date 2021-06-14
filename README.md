<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Thanks again! Now go create something AMAZING! :D
***
***
***
*** To avoid retyping too much info. Do a search and replace for the following:
*** github_username, repo_name, twitter_handle, email, project_title, project_description
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]



<!-- PROJECT LOGO -->
<br />
<p align="center">
  <h3 align="center">CCPROG 2 Machine Project</h3>

  <p align="center">
    A culminating activity (in parts) showing what we learned about in C language and algorithms
    <br />
    <a href="https://github.com/yazninja/CCPROG2MP"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/yazninja/CCPROG2MP/issues">Report Bug</a>
    ·
    <a href="https://github.com/yazninja/CCPROG2MP/issues">Request Feature</a>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary><h2 style="display: inline-block">Table of Contents</h2></summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

This project was made as a culmination of lessons we have learnt while studying the C language. Each Part of this Machine Project was tested and runned by themselves according to each of their specs. Learn more below.

* [Part 1](https://github.com/yazninja/CCPROG2MP/MP1)
* [Part 2](https://github.com/yazninja/CCPROG2MP/MP2)
* [Part 3](https://github.com/yazninja/CCPROG2MP/MP3)

* Extras
  * [GE03](https://github.com/yazninja/CCPROG2MP/GE03)
  * [Produce Data](https://github.com/yazninja/CCPROG2MP/tree/master/PRODUCE%20DATA)



### Built With

* [Dev C++](https://sourceforge.net/projects/orwelldevcpp/)
* [Visual Studio Code](https://code.visualstudio.com/)
* Compiler: [gcc (GCC) 11.1.0](https://gcc.gnu.org/codingconventions.html)


<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites

To run this code with your system you have to install the gcc compiler as a pre-requisite to run C code in your terminal.
* ##### Windows
  Windows users can easily open and compile the code using the [Dev C++](https://sourceforge.net/projects/orwelldevcpp/) program.<br>
  If you want to be able to run the code in Command Prompt/ Powershell, you will have to make sure that the GCC compiler is installed in your system. Running `gcc -v` can help you check what version (if installed) you have. If gcc is not installed you can download and install the [MinGW](https://sourceforge.net/projects/mingw/) fork of GCC
  <br>   
* ##### Linux
  * Arch
  ```sh
  sudo pacman -S gcc
  ```
  * Debian/ Ubuntu
  ```sh
  sudo apt install gcc -y
  ```
  * Redhat/ Fedora
  ```sh
  yum install gcc -y
  ```

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/yazninja/CCPROG2MP.git
   ```
2. Change directories to the Machine Project
   ```sh
   cd CCPROG2MP
   ```
2. Compile using gcc and run*
  * GE03
    ```sh
    gcc -Wall GE03/GE03-23.c -o GE03/GE03-23 && ./GE03/GE03-23
    ```
  * MP1
    ```sh
    gcc -Wall MP1/C1-18.c -o MP1/C1-18 && ./MP1/C1-18
    ```
  * MP2
    ```sh
    gcc -Wall MP2/MP2-18.c -o MP2/MP2-18 && ./MP2/MP2-18
    ```
  * MP3
    ```sh
    gcc -Wall MP3/main-18.c -o MP3/main-18 && ./MP3/main-18
    ```

  \* for Windows users, change `/` in accessing directories with `\` also run the code without the `./` at the beginning.


<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. As this project is done for class purpose, you can fork the repo if you want as I will keep the original as master. Though any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<!-- CONTACT -->
## Contact

Twitter - [@yazninjaa](https://twitter.com/yazninjaa)

Project Link: [https://github.com/yazninja/CCPROG2MP](https://github.com/yazninja/CCPROG2MP)


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/yazninja/CCPROG2MP.svg?style=for-the-badge
[contributors-url]: https://github.com/yazninja/CCPROG2MP/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/yazninja/CCPROG2MP.svg?style=for-the-badge
[forks-url]: https://github.com/yazninja/CCPROG2MP/network/members
[stars-shield]: https://img.shields.io/github/stars/yazninja/CCPROG2MP.svg?style=for-the-badge
[stars-url]: https://github.com/yazninja/CCPROG2MP/stargazers
[issues-shield]: https://img.shields.io/github/issues/yazninja/CCPROG2MP.svg?style=for-the-badge
[issues-url]: https://github.com/yazninja/CCPROG2MP/issues
[license-shield]: https://img.shields.io/github/license/yazninja/CCPROG2MP.svg?style=for-the-badge
[license-url]: https://github.com/yazninja/CCPROG2MP/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555