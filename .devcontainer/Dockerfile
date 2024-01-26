# Use Ubuntu as the base image
FROM ubuntu:22.04

# Set environment variables to prevent interactive prompts during installation
ENV DEBIAN_FRONTEND=noninteractive

# Update package lists and install essential tools and Zsh
RUN apt-get update -y && \
    apt-get install -y \
    zsh \
    curl \
    wget \
    git \
    fonts-powerline

# Install Clang and Clang-Tidy
RUN apt-get update -y && \
    apt-get install -y cmake clang clang-tidy

# Clean up
RUN apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Install Oh My Zsh
RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

# Install Powerlevel10k theme for Zsh
RUN git clone --depth=1 https://github.com/romkatv/powerlevel10k.git /root/.oh-my-zsh/themes/powerlevel10k && \
    echo "ZSH_THEME=\"powerlevel10k/powerlevel10k\"" >> /root/.zshrc

# Set up Oh My Zsh plugins
RUN sed -i 's/plugins=(git)/plugins=(git zsh-autosuggestions zsh-syntax-highlighting)/g' /root/.zshrc

# Install Oh My Zsh plugins
RUN git clone https://github.com/zsh-users/zsh-autosuggestions.git /root/.oh-my-zsh/custom/plugins/zsh-autosuggestions && \
    git clone https://github.com/zsh-users/zsh-syntax-highlighting.git /root/.oh-my-zsh/custom/plugins/zsh-syntax-highlighting

# Set Zsh as the default shell
RUN chsh -s /bin/zsh

# Start Zsh
CMD ["zsh"]

